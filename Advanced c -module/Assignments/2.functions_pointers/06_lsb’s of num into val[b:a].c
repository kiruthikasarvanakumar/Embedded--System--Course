/*
Name : S.Kiruthika
Date : 22-3-2024
Description : WAP to put the (b-a+1) lsb’s of num into val[b:a]
Sample input : Enter the value of 'num' : 11
               Enter the value of 'a' : 3
               Enter the value of 'b' : 5
               Enter the value of 'val': 174
Sample output : Result : 158

*/
#include <stdio.h>

int replace_nbits_from_pos(int, int, int, int);
int main() {

    //declaration
    int num, a, b, val, res = 0;
    
    //read the number , a , b, and value from the user
    printf("Enter the 'num' : ");
    scanf("%d", &num);
    printf("Enter the value of 'a' : ");
    scanf("%d", &a);
    printf("Enter the value of 'b' : ");
    scanf("%d", &b);
    printf("Enter the value of 'val': ");
    scanf("%d", &val);
    
    //store in the result and print
    res = replace_nbits_from_pos(num, a, b, val);
    
    printf("Result : %d\n", res);
    
    return 0;
}

// Function to replace n bits
int replace_nbits_from_pos(int num, int a, int b, int val) {
    int n, result, lsb, value, mask;

    // Calculate the number of bits to replace
    int i = b - a + 1;
    int pos = b;
    
    // Extract the (b-a+1) LSBs of num
    lsb = (((1 << i) - 1) & num) ;

    // Create a mask
    mask = ~(((1 << i) - 1) << (pos - i + 1));

    value = mask & val;

    //combine the bits from value
    result = value | lsb << (pos - i + 1);

    return result;
}
