/*
Name : S.Kiruthika
Date : 08-04-2024
Description :  WAP to implement atoi function
Sample input : Enter a numeric string: 12345
Sample output : String to integer is 12345

*/
#include <stdio.h>

int my_atoi(const char []);

int main() {
    char str[20];
    
    printf("Enter a numeric string: ");
    scanf("%s", str);
    
    printf("String to integer is %d\n", my_atoi(str));
    return 0;
}

int my_atoi(const char str[]) {
    int index = 0;
    int ret = 0;
    // Flag to check if the number is negative
    int flag = 0; 

    // Check for '+' or '-'
    if (str[0] == '+' || str[0] == '-') {
        // If the first character is '+' or '-', start from index 1 and set flag accordingly
        index = 1;
        if (str[0] == '-')
            flag = 1;
    }

    // Convert characters to digits
    while (str[index] >= '0' && str[index] <= '9') {
        ret = ret * 10 + (str[index] - '0');
        index++;
    }

    // If the number is negative, return the negative value
    if (flag)
        return -ret;

    return ret;
}
