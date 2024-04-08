/*
Name : S.Kiruthika
Date : 08-04-2024
Description :  WAP to reverse the given string using iterative method
Sample input : Enter a string : Hello World
Sample output : Reverse string is : dlroW olleH

*/
#include <stdio.h>
#include <string.h>

void reverse_iterative(char str[]);

int main()
{
    char str[30];
    
    //read the input from the user
    printf("Enter any string : ");
    scanf("%[^\n]", str);
    
    reverse_iterative(str);

    printf("Reversed string is: %s\n", str);
}
void reverse_iterative(char str[]) {
    int length = strlen(str);

    // Iterate the string
    for (int i = 0; i < length / 2; i++) {
        
        // Swap characters
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
}
