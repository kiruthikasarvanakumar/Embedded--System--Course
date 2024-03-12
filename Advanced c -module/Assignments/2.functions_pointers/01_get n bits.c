/*
Name : S.Kiruthika
Date : 12-3-2024
Description : WAP to get 'n' bits of a given number 
Sample input : Enter the number: 10
               Enter number of bits: 3
Sample output :  Result = 2

*/
#include <stdio.h>

     //function definition
     int get_bits(int num,int n){
         
         //create a mask with 'n' bits set to 1
        int mask = (1 << n) -1;
        return num & mask;
     }
    int main(){
        int num,n;
        
        //prompt the user to input a number and read the number
        printf("Enter a number: ");
        scanf("%d", &num);
        printf("Enter the number of bits: ");
        scanf("%d", &n);
        
        //function call
        int res = get_bits(num,n);
        printf("Result = %d\n", res);
        return 0;
    }

