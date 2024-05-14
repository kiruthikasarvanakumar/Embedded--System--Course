#include <stdio.h>
#include "decode.h"
#include "types.h"
#include <string.h>
#include "common.h"

/********************************************************************
 * FUNCTION DEFINITION:read_and_validate_decode_args
     ----> validates if correct type of files are passed or not
*/
Status read_and_validate_decode_args(char *argv[], DecodeInfo *decInfo)
{
    // Check if the file extension of the second argument is ".bmp"
    if (strcmp(strchr(argv[2], '.'), ".bmp") == 0)				
    {
        // If it's a BMP file, assign its name to the decoding information
	decInfo -> stego_image_fname = argv[2];;				
    }
    else
    {
        // If the file extension is not ".bmp", return failure status
	return e_failure;
    }
     // Check if the third argument is NULL (no output file specified)
    if (argv[3] == NULL)							
    {
	decInfo -> decoded_file_fname = "decoded.txt";				

    }else
    {
        // If an output file name is specified, assign it to the decoding information
	decInfo -> decoded_file_fname = argv[3];				
    }
    return e_success;
}


/********************************************************************
 * FUNCTION DEFINITION:
    ----> Description: Opens the stego image file and the decoded file for writing.

*/
Status get_files(DecodeInfo *decInfo)
{
    // Open the stego image file for reading
    decInfo->fptr_stego_image = fopen(decInfo->stego_image_fname, "r");			       
    
    // Check if the file opening was successful
    if (decInfo->fptr_stego_image == NULL)                                                     
    {
        // Print error message 
	perror("fopen");
	fprintf(stderr, "ERROR: Unable to open file %s\n", decInfo->stego_image_fname);

	return e_failure;
    }

     // Open the decoded file for writing
    decInfo->fptr_decoded_file = fopen(decInfo->decoded_file_fname, "w");			
    
    //check if the file opening was successful
    if (decInfo->fptr_decoded_file == NULL)						
    {
        // Print error message and return failure status
	perror("fopen");
	fprintf(stderr, "ERROR: Unable to open file %s\n", decInfo->decoded_file_fname);

	return e_failure;
    }

    return e_success;									
}

/********************************************************************
 * FUNCTION DEFINITION:
    ----> Description: Decodes the magic string from the stego image file and compares it with the provided magic string.
 
 */
Status decode_magic_string(FILE *fptr, char *magic_string, DecodeInfo *decInfo)
{

    // Move the file pointer to the beginning of the image data
    fseek(fptr, 54, SEEK_SET);		
    //Get the size of the magic string						
    int size = strlen(magic_string);

    // Iterate through the magic string characters
    for(int i = 0; i < size; i++)
    {
        //Read 8 bits 
	fread(decInfo -> image_data, 8, 1, decInfo -> fptr_stego_image);		
        //Decode the byte 
	decode_byte_from_lsb(decInfo -> image_data, decInfo);				
      
        //store the decoded byte
	decInfo -> magic_str[i] = decInfo -> one_byte;					
	decInfo -> magic_str[i+1] = '\0';						
    }
        //compare the decoded magic string
    if(strcmp(magic_string, decInfo -> magic_str) == 0)					
    {
	return e_success;
    }
    else
    {
	return e_failure;
    }
}

/********************************************************************
 * FUNCTION DEFINITION:
    ----> Description: Decodes the extension size from the stego image file.
 */
Status decode_extn_size(DecodeInfo *decInfo)
{
    //Decode the size of the extension
    decode_size_from_lsb(decInfo);				

    //store the decoded extension size
    decInfo -> extn_size = decInfo -> int_data;			

    return e_success;
}

/********************************************************************
 * FUNCTION DEFINITION:
    ----> Description: Decodes the extension of the secret file from the stego image file and compares it with the provided extension.
 */
Status decode_secret_file_extn(DecodeInfo *decInfo)
{
    // Get the size of the extension
    int size = decInfo -> extn_size;
    
    for(int i = 0; i < size; i++)
    {
        // Read 8 bits
	fread(decInfo -> image_data, 8, 1, decInfo -> fptr_stego_image);			
        
        //Decode the byte
	decode_byte_from_lsb(decInfo -> image_data, decInfo);					
        //Store the decoded byte
	decInfo -> extn_decoded_file[i] = decInfo -> one_byte;					
	decInfo -> extn_decoded_file[i+1] = '\0';						

    }
      
      //check if the decoded extension matches the extension of the decoded file
    if( strcmp( strstr(decInfo -> decoded_file_fname, "."), decInfo -> extn_decoded_file ) == 0 )	
    {
	return e_success;
    }
    else												
    {
        //if do not match reset the decoded file to "decoded.txt"
	decInfo -> decoded_file_fname = "decoded.txt";

	decInfo->fptr_decoded_file = fopen(decInfo->decoded_file_fname, "w");

	return e_success;
    }
}
/********************************************************************
 * FUNCTION DEFINITION:
    ----> Description: Decodes the size of the secret file from the stego image file.
 */
Status decode_secret_file_size(FILE *fptr_stego_image,DecodeInfo *decInfo)               
{
    //Buffer to store 32 byytes 
    char buff[32];                            
    int i,size=0;
    char get;

    //Read 32 bytes
    fread(buff,32,1,fptr_stego_image);           
    for(i=31;i>=0;i--)
    {
        //extract the lsb of each byte in the buffer
	get = buff[i] & 0x01;                    
	size = (get << i) | size;
    }
    decInfo->size_decoded_file = size;                 
    return e_success;
}

/********************************************************************
 * FUNCTION DEFINITION:
    ----> Description: Decodes the data of the secret file from the stego image file.
 */
Status decode_secret_file_data(DecodeInfo *decInfo)
{
    // Decode the data of the secret file from the stego image file
    decode_data_from_image(decInfo -> size_decoded_file, decInfo);		

    return e_success;
}

/************************************************************************
 * FUNCTION DEFINITION: do_decoding
*/
Status do_decoding(DecodeInfo *decInfo)
{
    if (get_files(decInfo) == e_success)
    {
	printf("INFO: Opening Required Files\n");
	if(decode_magic_string(decInfo -> fptr_stego_image, MAGIC_STRING, decInfo) == e_success)
	{
	    printf("INFO: Decoding Magic String\n");
        printf("INFO: Done.\n");
	    if(decode_extn_size(decInfo) == e_success)
	    {
		printf("INFO: Decoded Output File extension size\n");
        printf("INFO: Done.\n");
        printf("INFO: Output File not mentioned. Creating decoded.txt as default\n");
        printf("INFO: Opened decoded.txt\n");
		if(decode_secret_file_extn(decInfo) == e_success)
		{
		    printf("INFO: Done.Opened All Required Files\n");

		    if(decode_secret_file_size(decInfo->fptr_stego_image,decInfo) == e_success)
		    {
			printf("INFO: Decoding File Size\n");
            printf("INFO: Done.\n");

			if(decode_secret_file_data(decInfo) == e_success)
			{
			    printf("INFO: Decoding File Data\n");
                printf("INFO: Done\n");
			}
			else
			{
			    printf("Failed to encode secret data\n");
			    return e_failure;

			}


		    }
		    else
		    {
			printf("Failed to decode secret file size\n");
			return e_failure;
		    }
		}
		else
		{
		    printf("Failed to decode secret file extension\n");
		    return e_failure;
		}

	    }
	    else
	    {
		printf("Failed to encode extension size\n");
		return e_failure;
	    }
	}
	else
	{
	    printf("Failed to decode magic string\n");
	    return e_failure;
	}
    }
    else
    {
	printf("Open file is a failure\n");
	return e_failure;
    }

    return e_success;

}
/********************************************************************
 * FUNCTION DEFINITION:
    ----> Description: Decodes data from the stego image file based on the provided size and writes it to the decoded file.
 
 */
Status decode_data_from_image(int size, DecodeInfo *decInfo)
{
    // Iterate through the data to be decoded
    for(int i = 0; i < size; i++)							
    {
        // Read 8 bits 
        fread(decInfo->image_data, 8, 1, decInfo->fptr_stego_image);		
        // Decode the byte from the LSB
        decode_byte_from_lsb(decInfo->image_data, decInfo);			
        // Get a pointer to the decoded byte
        decInfo->decoded_byte = &(decInfo->one_byte);				
        // Write the decoded byte 
        fwrite(decInfo->decoded_byte, 1, 1, decInfo->fptr_decoded_file);		
    }

    return e_success;
}

/********************************************************************
 * FUNCTION DEFINITION:
  ----> Description: Decodes a byte from the LSB (Least Significant Bit) of the provided image buffer.
 */
Status decode_byte_from_lsb(char *image_buffer, DecodeInfo *decInfo)
{
    char data = 0x00;
    // Iterate through the 8 bits of the byte
    for(int i = 0; i < 8; i++)
    {
        // Shift left by 1 bit 
        data = data << 1;
        
        data = data | image_buffer[i] & 0x01;			
    }
    // Store the decoded byte
    decInfo->one_byte = data;					
}

/********************************************************************
 * FUNCTION DEFINITION:
   ----> Description: Decodes the size of data from the LSB (Least Significant Bit) of the stego image file.
 
 */
Status decode_size_from_lsb(DecodeInfo *decInfo)
{
    char str[32];								

    int int_data = 0x00;

    // Read 32 bits 
    fread(str, 32, 1, decInfo->fptr_stego_image);					

    // Iterate through the 32 bits to decode the size
    for(int i = 0; i < 32; i++)
    {
        // Shift left by 1 bit
        int_data = int_data << 1;
       
        int_data = int_data | str[i] & 0x01;						
    }

    // Store the decoded size in the DecodeInfo structure
    decInfo->int_data = int_data;								
}
