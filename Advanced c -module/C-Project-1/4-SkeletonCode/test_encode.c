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