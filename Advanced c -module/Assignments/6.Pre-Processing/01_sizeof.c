
/*
Name : S.Kiruthika
Date : 30-04-2024
Description :  WAP to define a macro SIZEOF(x), without using sizeof operator
Sample output : Size of int : 4 bytes
                Size of char : 1 byte
                Size of float : 4 bytes
                Size of double : 8 bytes
                Size of unsigned int : 4 bytes
                Size of long int : 8 bytes
                ----
                ----
                ----

*/
#include <stdio.h>

//macro definition
#define SIZEOF(x)  (char *)(&x + 1) - (char *)(&x)

int main() {
    //variable declarations
    int sint;                                                                   
    unsigned int uint;

    char schar;
    unsigned char uchar;

    float fl;
    double db;

    long int lint;
    unsigned long int ulint;

    long double ld;
    long long int llint;

    short int shint;
    unsigned short int ushint;

    //printing the size of types
    printf("Size of int: %td bytes\n", SIZEOF(sint));
    printf("Size of char: %td byte\n", SIZEOF(schar));
    printf("Size of float: %td bytes\n", SIZEOF(fl));
    printf("Size of double: %td bytes\n", SIZEOF(db));
    printf("Size of unsigned int: %td bytes\n", SIZEOF(uint));
    printf("Size of long int: %td bytes\n", SIZEOF(lint));
    printf("---\n");
    printf("---\n");
    printf("---\n");


    return 0;
}
