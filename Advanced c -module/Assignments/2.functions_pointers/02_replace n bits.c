/*
Name : S.Kiruthika
Date : 21-3-2024
Description : WAP to replace 'n' bits of a given number
Sample input : Enter the number: 10
               Enter number of bits: 3
               Enter the value: 12
Sample output :  Result = 12

*/
#include <stdio.h>

int replace_nbits(int num, int n, int val) {
    
    //create a mask
    int mask = (1<<n)-1;
    
    // Clear 'n' rightmost bits of num and set them to val
    return (num & ~mask) | (val & mask);
}

int main()
{
    //declare the variable
    int num, n, val, Result = 0;
    
    //read the number from the user
    printf("Enter the number: ");
    scanf("%d", &num);
    
    //read the number of bits from the user
    printf("Enter the number of bits: ");
    scanf("%d", &n);
    
    //read the value from the user
    printf("Enter the value: ");
    scanf("%d", &val);
    
    //call the function to replace
    Result = replace_nbits(num, n, val);
    
    //print the result after replacement
    printf("Result = %d\n", Result);
}
