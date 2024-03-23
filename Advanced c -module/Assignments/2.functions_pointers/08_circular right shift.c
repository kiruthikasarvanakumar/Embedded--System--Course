/*
Name : S.Kiruthika
Date : 23-3-2024
Description : WAP to implement Circular right shift
Sample input : Enter num: 12
               Enter n : 3
Sample output : Result : 10000000 00000000 00000000 00000001
*/
#include <stdio.h>

// Function prototypes
int circular_right(int, int);
int print_bits(int);

int main() {
    int num, n, ret;

    printf("Enter the num: ");
    scanf("%d", &num);

    printf("Enter n: ");
    scanf("%d", &n);

    ret = circular_right(num, n);

    printf("Result in Binary: ");
    print_bits(ret);
    
    return 0;
}

// Function to perform a circular right shift
int circular_right(int num, int n) {
    unsigned int a = num;
    int result;

    int value = (num >> n) & (~(((1 << n) - 1) << 32 - n)); 
    int right_shift = (((1 << n) - 1) & num) << (32 - n); 
    
    // bitwise OR operation
    result = right_shift | value; 

    return result;
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
