/*
Name : S.Kiruthika
Date : 12-04-2024
Description :  WAP to implement itoa function
Sample input : Enter the number : a1234
Sample output : Integer to string is 0

*/
#include <stdio.h>

int atoi(const char *str);
void itoa(int num, char str[]);

int main() {
    
    // Assuming a maximum of 20 characters for the input
    char input[20]; 
    printf("Enter the number: ");
    scanf("%s", input);

    // Convert input string to integer
    int num = atoi(input);

    // Check if conversion was successful
    if (num == 0) {
        printf("Integer to string is 0\n");
    } else {
        
        // Assuming a maximum of 20 characters 
        char str[20]; 
        itoa(num, str);
        printf("Integer to string is %s\n", str);
    }

    return 0;
}

int atoi(const char *str) {
    int num = 0;
    int sign = 1;
    int i = 0;

    while (str[i] == ' ') {
        i++;
    }
  
    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }

    // Convert digits to integer
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            num = num * 10 + (str[i] - '0');
            i++;
        } else {
            // Non-numeric character found
            break;
        }
    }

    return sign * num;
}

void itoa(int num, char str[]) {
    int i = 0;
    int isNegative = 0;

    // Handle 0 
    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return;
    }

    //Handle negative numbers
    if (num < 0) {
        isNegative = 1;
        num = -num;
    }

    // Process individual digits
    while (num != 0) {
        int remainder = num % 10;
        str[i++] = remainder + '0';
        num = num / 10;
    }

    /* If the number is negative, append '-' */
    if (isNegative)
        str[i++] = '-';

    /* Append string terminator */
    str[i] = '\0'; 

    /* Reverse the string */
    int start = 0;
    int end = i - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}
