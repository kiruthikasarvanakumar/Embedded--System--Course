/*
Name : S.Kiruthika
Date : 21-3-2024
Description : WAP to print 'n' bits from LSB of a number
Sample input : Enter the number: 10
               Enter number of bits: 12
Sample output : Binary form of 10: 0 0 0 0 0 0 0 0 1 0 1 0 

*/
#include <stdio.h>

// Function to print 'n' bits from LSB of a number
void print_bits(int num, int n) {
    
    // print 'n' bits
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", (num >> i) & 1);
    }
    printf("\n");
}

int main() {
    int num, n;

    //read the number from the user
    printf("Enter the number: ");
    scanf("%d", &num);
    
    //read the number of bits
    printf("Enter number of bits: ");
    scanf("%d", &n);

    printf("Binary form of %d:", num);
    print_bits(num, n);

    return 0;
}
