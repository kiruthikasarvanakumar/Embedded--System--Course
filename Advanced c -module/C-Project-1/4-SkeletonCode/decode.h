
#ifndef DECODE_H
#define DECODE_H

#include "types.h" // Contains user defined types
/* 
 * Structure to store information required for
 * decoding secret file from stego Image
 * Info about output and intermediate data is
 * also stored
 */

#define MAX_SECRET_BUF_SIZE 1
#define MAX_IMAGE_BUF_SIZE (MAX_SECRET_BUF_SIZE * 8)
#define MAX_FILE_SUFFIX 4
#define MAGIC_STR_SIZE 2

typedef struct _DecodeInfo
{
    /* Stego Image Info */
    char *stego_image_fname;		  		
    FILE *fptr_stego_image;		  					
    char image_data[MAX_IMAGE_BUF_SIZE];               
    

    /* Decoded File Info */
    char *decoded_file_fname;				
    FILE *fptr_decoded_file;				
    char magic_str[MAGIC_STR_SIZE];			
    char one_byte;					
    char *decoded_byte;					
    int int_data;					
    int extn_size;					
    char extn_decoded_file[MAX_FILE_SUFFIX];		
    long size_decoded_file;				

} DecodeInfo;


/* Decoding function prototype */

/* Read and validate Decode args from argv */
Status read_and_validate_decode_args(char *argv[], DecodeInfo *decInfo);

/* Perform the decoding */
Status do_decoding(DecodeInfo *decInfo);

/* Get File pointers for i/p and o/p files */
Status get_files(DecodeInfo *decInfo);

/* Extract Magic String */
Status decode_magic_string(FILE *fptr, char *magic_string, DecodeInfo *decInfo);

/* Decode extension size */
Status decode_extn_size(DecodeInfo *decInfo);

/* Decode secret file extenstion */
Status decode_secret_file_extn(DecodeInfo *decInfo);

/* Decode secret file size */
Status decode_secret_file_size(FILE *fptr_stego_image,DecodeInfo *decInfo);

/* Decode secret file data*/
Status decode_secret_file_data(DecodeInfo *decInfo);

/* Decode function, which does the real decoding */
Status decode_data_from_image(int size, DecodeInfo *decInfo);

/* Decode a byte from LSBs of image data array */
Status decode_byte_from_lsb(char *image_buffer, DecodeInfo *decInfo);

/* Generic function to decode interger */
Status decode_size_from_lsb(DecodeInfo *decInfo);

#endif
