#include <stdio.h>
#include <string.h>
#include "encode.h"
#include "types.h"
#include "common.h"

/*********************************************************************************
 * Function DEFINITION: get_image_size_for_bmp
   ----> Retrieves the size of the image data in bytes from a BMP file.
 */
uint get_image_size_for_bmp(FILE *fptr_image) 
{
    uint width, height;
    //Move the file pointer
    fseek(fptr_image, 18, SEEK_SET);

    /* Read the width and height of the image from the BMP file */
    fread(&width, sizeof(uint), 1, fptr_image);
    fread(&height, sizeof(uint), 1, fptr_image);
    return width * height * 3;
}

/*********************************************************************************
 * Function DEFINITION: open_files
   ----> Opens the source image, secret file, and stego image file for encoding.
 */
Status open_files(EncodeInfo *encInfo) {
    /* Open the source image file */
    encInfo->fptr_src_image = fopen(encInfo->src_image_fname, "r");
    if (encInfo->fptr_src_image == NULL) 
    {
        perror("fopen");
        fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->src_image_fname);
        return e_failure;
    }

    /* Open the secret file */
    encInfo->fptr_secret = fopen(encInfo->secret_fname, "r");
    if (encInfo->fptr_secret == NULL) 
    {
        perror("fopen");
        fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->secret_fname);
        // Close opened files before returning
        fclose(encInfo->fptr_src_image); 
        return e_failure;
    }

    /* Open the stego image file */
    encInfo->fptr_stego_image = fopen(encInfo->stego_image_fname, "w");
    if (encInfo->fptr_stego_image == NULL) 
    {
        perror("fopen");
        fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->stego_image_fname);
        fclose(encInfo->fptr_src_image);
        fclose(encInfo->fptr_secret);
        return e_failure;
    }

    return e_success;
}

/*********************************************************************************
 * Function DEFINITION: read_and_validate_encode_args
   ----> Reads and validates command-line arguments for encoding.
*/

Status read_and_validate_encode_args(char *argv[], EncodeInfo *encInfo) 
{
    /* Check if source image file is provided*/
    if (argv[2] != NULL && strcmp(strstr(argv[2], "."), ".bmp") == 0) 
    {
        encInfo->src_image_fname = argv[2];
    } 
    else 
    {
        return e_failure;
    }

    /* Check if secret file is provided*/
    if (argv[3] != NULL && strcmp(strstr(argv[3], "."), ".txt") == 0) 
    {
        encInfo->secret_fname = argv[3];
    } 
    else 
    {
        return e_failure;
    }

    /* Set the stego image file name; default to "stego.bmp" */
    encInfo->stego_image_fname = (argv[4] != NULL) ? argv[4] : "stego.bmp";
    
    return e_success;
}

/*********************************************************************************
 * Function DEFINITION: Get the size of the secret file
*/

long get_file_size(FILE *fptr) 
{
    fseek(fptr, 0, SEEK_END);
    return ftell(fptr);
}
/*********************************************************************************
 * Function DEFINITION: check_capacity
   ----> Check if the image has enough capacity to encode the secret file 
*/

Status check_capacity(EncodeInfo *encInfo) 
{
        /* Calculate the image capacity and size of the secret file */
    encInfo->image_capacity = get_image_size_for_bmp(encInfo->fptr_src_image);
    encInfo->size_secret_file = get_file_size(encInfo->fptr_secret);

        /* Check if the image capacity is enough*/
    if (encInfo->image_capacity > (54 + 16 + 32 + 32 + 32 + (encInfo->size_secret_file * 8))) 
    {
        return e_success;
    } 
    else 
    {
        return e_failure;
    }
}

/*********************************************************************************
 * Function DEFINITION: 
*/
Status copy_bmp_header(FILE *fptr_src, FILE *fptr_stego) 
{
    char header[54];
    fseek(fptr_src, 0, SEEK_SET);
    fread(header, sizeof(char), 54, fptr_src);
    fwrite(header, sizeof(char), 54, fptr_stego);
    return e_success;
}
/*********************************************************************************
 * Function DEFINITION: 
   ----> Encode the magic string into the image 
*/

Status encode_magic_string(char *magic_str, EncodeInfo *encInfo) 
{
    encode_data_to_image(magic_str, strlen(magic_str), encInfo);
    return e_success;
}

/*********************************************************************************
 * Function DEFINITION: 
   ----> Encode the secret file extension size into the stego image 
*/
Status encode_extn_size(int size, EncodeInfo *encInfo) 
{
    encode_size_to_lsb(size, encInfo);
    return e_success;
}
/*********************************************************************************
 * Function DEFINITION: 
   ----> Encode the secret file extension into the stego image 
*/
Status encode_secret_file_extn(char *file_extn, EncodeInfo *encInfo) 
{
    encode_data_to_image(file_extn, strlen(file_extn), encInfo);
    return e_success;
}
/*********************************************************************************
 * Function DEFINITION: 
   ----> Encode the secret file size into the stego image 
*/
Status encode_secret_file_size(int file_size, EncodeInfo *encInfo) 
{
    encode_size_to_lsb(file_size, encInfo);
    return e_success;
}
/*********************************************************************************
 * Function DEFINITION: 
   ----> Encode the secret file data into the stego image 
*/
Status encode_secret_file_data(EncodeInfo *encInfo) 
{
    fseek(encInfo->fptr_secret, 0, SEEK_SET);
    char str[encInfo->size_secret_file];
    fread(str, encInfo->size_secret_file, 1, encInfo->fptr_secret);
    encode_data_to_image(str, encInfo->size_secret_file, encInfo);
    return e_success;
}
/*********************************************************************************
 * Function DEFINITION: 
   ----> Copy remaining image data 
*/
Status copy_remaining_img_data(FILE *fptr_src, FILE *fptr_dest) 
{
    char ch;
    while (fread(&ch, 1, 1, fptr_src) > 0) 
    {
        fwrite(&ch, 1, 1, fptr_dest);
    }
    return e_success;
}
/*********************************************************************************
 * Function DEFINITION: 
   ----> Encode a byte into LSB of image data array 
*/
Status encode_byte_to_lsb(char data, char *image_buffer) 
{
    for (int i = 0; i < 8; i++) 
    {
        image_buffer[i] = (image_buffer[i] & 0xFE) | ((data >> (7 - i)) & 1);
    }
    return e_success;
}
/*********************************************************************************
 * Function DEFINITION: 
   ----> Encode data into the stego image 
*/
Status encode_data_to_image(char *data, int size, EncodeInfo *encInfo) 
{
    for (int i = 0; i < size; i++) 
    {
        fread(encInfo->image_data, 8, 1, encInfo->fptr_src_image);
        encode_byte_to_lsb(data[i], encInfo->image_data);
        fwrite(encInfo->image_data, 8, 1, encInfo->fptr_stego_image);
    }
    return e_success;
}
/*********************************************************************************
 * Function DEFINITION: 
   ----> Encode size into LSB of image data array 
*/
Status encode_size_to_lsb(int size, EncodeInfo *encInfo) 
{
    char str[32];
    fread(str, 32, 1, encInfo->fptr_src_image);
    for (int i = 0; i < 32; i++) 
    {
        str[i] = (str[i] & 0xFE) | ((size >> (31 - i)) & 1);
    }
    fwrite(str, 32, 1, encInfo->fptr_stego_image);
    return e_success;
}
/*********************************************************************************
 * Function DEFINITION: 
   ----> Get image size and dimensions 
*/
void get_image_size_and_dimensions(FILE *fptr_image, uint *width, uint *height) 
{
    fseek(fptr_image, 18, SEEK_SET);
    fread(width, sizeof(uint), 1, fptr_image);
    fread(height, sizeof(uint), 1, fptr_image);
}
/*********************************************************************************
 * Function DEFINITION: do_encoding
*/
Status do_encoding(EncodeInfo *encInfo) 
{
    if (open_files(encInfo) == e_success) 
    {
        uint width, height;
        get_image_size_and_dimensions(encInfo->fptr_src_image, &width, &height);
        printf("Width = %d\n", width);
        printf("Height = %d\n", height);
        
        printf("INFO: Opening required files\n");
        printf("INFO: Done.\n");
        if (check_capacity(encInfo) == e_success) 
        {
            printf("Check capacity is successful\n");
            printf("INFO: Done.\n");
            if (copy_bmp_header(encInfo->fptr_src_image, encInfo->fptr_stego_image) == e_success) 
            {
                printf("INFO: Copying Image Header\n");
                printf("INFO: Done.\n");
                if (encode_magic_string(MAGIC_STRING, encInfo) == e_success) 
                {
                    printf("INFO: Encoded Magic String\n");
                    printf("INFO: Done.\n");
                    if (encode_extn_size(strlen(encInfo->extn_secret_file), encInfo) == e_success) 
                    {
                        printf("INFO: Encoded secret.txt File Size Extension\n");
                        printf("INFO: Done.\n");
                        if (encode_secret_file_extn(encInfo->extn_secret_file, encInfo) == e_success) 
                        {
                            printf("INFO: Encoded secret.txt File Extension\n");
                            printf("INFO: Done.\n");
                            if (encode_secret_file_data(encInfo) == e_success) 
                            {
                                printf("INFO: Encoded secret.txt File Data\n");
                                printf("INFO: Done.\n");
                                if (encode_secret_file_size(encInfo->size_secret_file, encInfo) == e_success) 
                                {
                                    printf("INFO: Encoded secret.txt File Size\n");
                                    printf("INFO: Done.\n");
                                    if (copy_remaining_img_data(encInfo->fptr_src_image, encInfo->fptr_stego_image) == e_success) 
                                    {
                                        printf("INFO: Copying Left Over Data\n");
                                        printf("INFO: Done.\n");
                                        return e_success;
                                    } 
                                    else 
                                    {
                                        printf("Failed to copy remaining data\n");
                                    }
                                } 
                                else 
                                {
                                    printf("Failed to encode secret file size\n");
                                }
                            } 
                            else 
                            {
                                printf("Failed to encode secret file data\n");
                            }
                        } 
                        else 
                        {
                            printf("Failed to encode secret file extension\n");
                        }
                    } 
                    else 
                    {
                        printf("Failed to encode extension size\n");
                    }
                } 
                else 
                {
                    printf("Failed to encode magic string\n");
                }
            } 
            else 
            {
                printf("Failed to copy BMP header\n");
            }
        } 
        else 
        {
            printf("Image does not have sufficient size for encoding\n");
        }
    } 
    else 
    {
        printf("Failed to open the files\n");
    }
    return e_failure;
}
