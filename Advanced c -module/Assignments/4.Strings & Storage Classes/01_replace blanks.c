
/*
Name : S.Kiruthika
Date : 08-04-2024
Description : WAP to replace each string of one or more blanks by a single blank
Sample input : Enter the string with more spaces in between two words
               Pointers     are               sharp     knives.
Sample output : Pointers are sharp knives.

*/
#include <stdio.h>

void replace_blank(char []);

int main()
{
    char str[100];
    
    //read the input from the user
    scanf("%[^\n]", str);
    
    replace_blank(str);
    
    printf("%s\n", str);
    
    return 0; 
}

void replace_blank(char str[]) {
    int i, j;
    for (i = 0, j = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' || (i > 0 && str[i - 1] != ' ')) {
            // If current character is not a space or it's not consecutive spaces
            str[j++] = str[i];
        }
    }
    // Null terminate the string
    str[j] = '\0'; 
}
