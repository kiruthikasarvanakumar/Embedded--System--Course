/*
Name : S.Kiruthika
Date : 21-3-2024
Description : WAP to replace 'n' bits of a given number
Sample input : Enter the number: 12
               Enter number of bits: 3
               Enter the value: 4
Sample output :  Result = 3

*/
#include <stdio.h>
int get_nbits_from_pos(int, int, int); 
int main()
{
    //declare the variable
    int num, n, pos, Result = 0;
    
    //read the number from the user
    printf("Enter the number: ");
    scanf("%d", &num);
    
    //read the number of bits from the user
    printf("Enter number of bits: ");
    scanf("%d", &n);
    
    //read the position from the user
    printf("Enter the pos: ");
    scanf("%d", &pos);
    
    //call the function to get 'n' bits from the given position 
    Result = get_nbits_from_pos(num, n, pos);
    
    printf("Result = %d\n", Result);
}

int get_nbits_from_pos(int num, int n, int pos) {
    
    //create the mask
    int mask = ((1 << n) - 1) << (pos - n + 1);
    int result = (mask & num) >> (pos - n + 1);
    return result;             
}
