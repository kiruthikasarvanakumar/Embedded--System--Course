/*
Name : S.Kiruthika
Date : 23-3-2024
Description : WAP to implement Circular left shift
Sample input : Enter num: 12
               Enter n : 3
Sample output : Result in Binary: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0

*/
#include <stdio.h>

// Function prototype
int circular_left(int, int);
int print_bits(int);

int main() {
    int num, n, ret;

    printf("Enter the num: ");
    scanf("%d", &num);

    printf("Enter n: ");
    scanf("%d", &n);

    ret = circular_left(num, n);

    printf("Result in Binary: ");
    print_bits(ret);
    
}

// Function to perform a circular left shift
int circular_left(int num, int n) {
    unsigned int a = num;                      
 
    return(num << n) | a >> (32 - n) ;  
}

int print_bits(int ret) {
    // Print binary representation using a for loop
    for (int i = 0; i < 32; i++) {
        if (ret & (1 << (31 - i)))
            printf("1 ");
        else
            printf("0 ");
    }
    printf("\n");

    return 0;
}
