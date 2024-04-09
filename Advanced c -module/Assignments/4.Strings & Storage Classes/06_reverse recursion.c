/*
Name : S.Kiruthika
Date : 09-04-2024
Description :  WAP to reverse the given string using iterative method
Sample input : Enter a string : Hello World
Sample output : Reverse string is : dlroW olleH

*/
#include <stdio.h>

void reverse_recursive(char str[], int index, int len);
int main() {
    char str[30];
    
    printf("Enter any string: ");
    scanf("%[^\n]", str);
    
    // Calculate length of string
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    
    // Reverse the string recursively
    reverse_recursive(str, 0, len - 1);
    
    printf("Reversed string is %s\n", str);
    return 0;
}


void reverse_recursive(char str[], int index, int end) {
        // Base case
    if (index >= end)
        return;
    // Swap characters at start and end indices
    char temp = str[index];
    str[index] = str[end];
    str[end] = temp;
    // Recur for substring excluding the swapped characters
    reverse_recursive(str, index + 1, end - 1);
}
