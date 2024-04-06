
/*
Name : S.Kiruthika
Date : 06-04-2024
Description : WAP to count no. of characters, words and lines, entered through stdin
Sample input : Hello world
               Dennis Ritchie
               Linux
Sample output : Character count : 33
                Line count : 3
                Word count : 5

*/
#include <stdio.h>

int main() {

    // Initialize pre_ch with null character
    char ch, pre_ch = '\0'; 
    int char_count = 0, word_count = 0, line_count = 0;

    
    // Read characters until EOF
    while ((ch = getchar()) != EOF) {
        char_count++; // Increment character count

        // Check for newline character
        if (ch == '\n') {
            line_count++; // Increment line count
        }

        // Check for space character
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r' || ch == '\v' || ch == '\f') {

            
            // If the previous character was not a space, we've reached the end of a word
            if (pre_ch != ' ' && pre_ch != '\t' && pre_ch != '\n' && pre_ch != '\r' && pre_ch != '\v' && pre_ch != '\f') {
               // Increment word count
                word_count++; 
            }
        }

        // Update pre_ch for the next iteration
        pre_ch = ch; 
    }

    // Check if its a word
    if (pre_ch != ' ' && pre_ch != '\t' && pre_ch != '\n' && pre_ch != '\r' && pre_ch != '\v' && pre_ch != '\f') {

        // Increment word count
        word_count++; 
    }

    // Output the counts
    printf("character count: %d\n", char_count);
    printf("Line count: %d\n", line_count);
    printf("Word count: %d\n", word_count);

    return 0;
}
