/*
Name: S.KIRUTHIKA

Date of Submission: 12-05-2024

Project Name:LSB Image Steganography

Description:  Steganography is the art and science of concealing information within other 
              non-secret data, such as images, audio files, or text, in a way that the existence of 
              the hidden information is undetectable to the casual observer. It operates on the principle 
              that the secret message is embedded within a carrier medium in such a way that it is invisible to anyone 
              not aware of its presence.
Input CLAs:
		1. -e (for Encoding)
			2. Innocent image (BMP image file) 
			3. Secret file (TXT file)
			4. Stego image's name [Optional]
		
		1. -d (for Decoding)
			2. Stego image file
			3. Decode file's name [Optional]
Sample execution: -

Test Case 1:

./a.out -e beautiful.bmp secret.txt stego.bmp
###ENCODING PROCEDURE STARTED###
Read and validate encode argument successful
Width = 1024
Height = 768
INFO: Opening required files
INFO: Done.
Check capacity is successful
INFO: Done.
INFO: Copying Image Header
INFO: Done.
INFO: Encoded Magic String
INFO: Done.
INFO: Encoded secret.txt File Size Extension
INFO: Done.
INFO: Encoded secret.txt File Extension
INFO: Done.
INFO: Encoded secret.txt File Data
INFO: Done.
INFO: Encoded secret.txt File Size
INFO: Done.
INFO: Copying Left Over Data
INFO: Done.
###ENCODING DONE SUCCESSFULLY###

Test Case 2:

./a.out -d stego.bmp output.txt

###DECODING PROCEDURE STARTED###
Read and validate decode argument successful
INFO: Opening Required Files
INFO: Decoding Magic String
INFO: Done.
INFO: Decoded Output File extension size
INFO: Done.
INFO: Output File not mentioned. Creating decoded.txt as default
INFO: Opened decoded.txt
INFO: Done.Opened All Required Files
INFO: Decoding File Size
INFO: Done.
INFO: Decoding File Data
INFO: Done
###DECODING DONE SUCCESSFULLY###

Test Case 3:

./a.out

Please pass required CLAs

*/

#include <stdio.h>
#include <string.h>
#include "encode.h"
#include "types.h"
#include "decode.h"

OperationType check_operation_type(char *argv[]);

int main(int argc, char *argv[]) {
    // Check if the correct number of command-line arguments are provided
    if (argc < 4) {
        printf("Please pass required CLAs\n");
        return 1;
    }

    // Check operation type
    OperationType op_type = check_operation_type(argv);
    switch (op_type) {
        case e_encode: {
            EncodeInfo encInfo;
            printf("###ENCODING PROCEDURE STARTED###\n");
            if (read_and_validate_encode_args(argv, &encInfo) == e_success) 
            {
                printf("Read and validate encode argument successful\n");
                if (do_encoding(&encInfo) == e_success) 
                {
                    printf("###ENCODING DONE SUCCESSFULLY###\n");
                } 
                else 
                {
                    printf("Failed to do encoding\n");
                }
            } 
            else 
            {
                printf("Failed: Read and validate encode argument\n");
            }
            break;
        }
        case e_decode: {
            DecodeInfo decInfo;
            printf("###DECODING PROCEDURE STARTED###\n");
            if (read_and_validate_decode_args(argv, &decInfo) == e_success) {
                printf("Read and validate decode argument successful\n");
                if (do_decoding(&decInfo) == e_success) 
                {
                    printf("###DECODING DONE SUCCESSFULLY###\n");
                } 
                else 
                {
                    printf("Failed to do decoding\n");
                }
            } 
            else 
            {
                printf("Failed: Read and validate decode argument\n");
            }
            break;
        }
        case e_unsupported:
            printf("Unsupported operation\n");
            break;
    }
    return 0;
}

OperationType check_operation_type(char *argv[]) {
    if (strcmp(argv[1], "-e") == 0)
        return e_encode;
    else if (strcmp(argv[1], "-d") == 0)
        return e_decode;
    else
        return e_unsupported;
}
