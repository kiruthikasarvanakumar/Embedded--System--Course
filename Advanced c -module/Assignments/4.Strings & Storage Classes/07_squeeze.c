/*
Name : S.Kiruthika
Date : 12-04-2024
Description :   Squeeze the character in s1 that matches any character in the string s2
Sample input : Enter s1 : Dennis Ritchie
               Enter s2 : Linux
Sample output : After squeeze s1 : Des Rtche

*/
#include <stdio.h>

void squeeze(char *, char *);

int main()
{
    char str1[30], str2[30];
    
    //input string 1
    printf("Enter s1 : ");
    scanf("%[^\n]", str1);
    getchar();

    //input string 2
    printf("Enter s2 : ");
    scanf("%[^\n]", str2);
    getchar();

    //call the squeeze function
    squeeze(str1, str2);
    
    //ouput after  squeezing
    printf("After squeeze s1 : %s\n", str1);
    
}

//function to squeeze
void squeeze(char*s1, char*s2) {
    int i, j, k;
    int flag;

   //loop for character string 1
    for (i = j = 0; s1[i] != '\0'; i++) {
        flag = 0;

        //loop for character string 2
        for (k = 0; s2[k] != '\0'; k++) {
            // If the current character in s1 matches any character in s2, set flag
            if (s1[i] == s2[k]) {
                flag = 1;
                break;
            }
        }

        // If the current character in s1 is not found in s2, copy it to the result
        if (!flag) {
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}
