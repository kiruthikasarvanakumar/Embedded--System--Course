/*
Name : S.Kiruthika
Date : 21-3-2024
Description : WAP to toggle 'n' bits from given position of a number
Sample input : Enter the number: 10
               Enter number of bits: 3
               Enter the value: 5
Sample output :  Result = 50

*/
#include <stdio.h>

int toggle_nbits_from_pos(int num, int n, int pos) {
    
    // Create a mask to toggle 'n' bits from the specified position
    int mask = ((1 << n) - 1) << (pos - n + 1); 
    
    // Toggle the bits using XOR (^) operation
    int result= mask ^ num;
    return result; 
}

int main()
{
    int num, n, pos, Result = 0;
    
    //read the number from the user
    printf("Enter the number: ");
    scanf("%d", &num);
    //read the number of bits from the user
    printf("Enter the number of bits: ");
    scanf("%d", &n);
    //read the position from the user
    printf("Enter the pos: ");
    scanf("%d", &pos);
    
    Result = toggle_nbits_from_pos(num, n, pos);
    
    printf("Result = %d\n", Result);
}
