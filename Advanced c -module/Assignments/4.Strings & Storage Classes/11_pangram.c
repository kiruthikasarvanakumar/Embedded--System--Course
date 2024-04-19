/*
Name : S.Kiruthika
Date : 18-04-2024
Description : WAP to check given string is Pangram or not
Sample input : Enter the string: The quick brown fox jumps over the lazy dog
Sample output : The Entered String is a Pangram String
*/

#include <stdio.h>

int pangram(char *str);

int main() {
    char str[100];

    // Read the input from the user
    printf("Enter a string: ");
    scanf("%99[^\n]", str);
    // Consume the newline character
    getchar(); 

    

    // If all the alphabets are present, print it is a pangram; otherwise, print it's not a pangram
    if (pangram(str)) {
        printf("The entered string is a pangram string\n");
    } else {
        printf("The entered string is not a pangram string\n");
    }

    return 0;
}

int pangram(char *str) {
    // Initialize an array name as present
    int present[26] = {0}; 

    // Iterate through each character in the string
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        // Convert uppercase letters to lowercase
        if ('A' <= c && c <= 'Z') {
            c += 32; // Convert to lowercase
        }
        // Check if the character is a lowercase alphabet
        if ('a' <= c && c <= 'z') { 
            // Mark the corresponding index as present
            present[c - 'a'] = 1; 
        }
    }

    // Check if all letters have been present at least once
    for (int i = 0; i < 26; i++) {
        if (!present[i]) {
            return 0; 
        }
    }
    // All letters have been present, return true (1) - pangram
    return 1; 
}
