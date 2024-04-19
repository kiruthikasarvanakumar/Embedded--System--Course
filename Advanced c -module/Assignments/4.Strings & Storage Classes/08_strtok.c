/*
Name : S.Kiruthika
Date : 19-04-2024
Description : WAP to implement strtok function
Sample input : Enter string1 : Bangalore;;::---Chennai:;Kolkata:;Delhi:-:Mumbai
               Enter string2 : ;./-:
Sample output : Tokens :
                Bangalore
                Chennai
                Kolkata
                Delhi
                Mumbai
*/
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>

// Function prototype
char *my_strtok(char str[], const char delim[]);

int main()
{
    char str[50], delim[50];
    
    //  read input string from the user
    printf("Enter string1 : ");
    scanf("%s", str);
    
    __fpurge(stdout);
 
    printf("Enter string2 : ");
    scanf("\n%s", delim);
    __fpurge(stdout);
    
    char *token = my_strtok(str, delim);
    printf("Tokens :\n");
    
    // Print each token
    while (token)
    {
        printf("%s\n", token);
        token = my_strtok(NULL, delim);
    }
}
char *my_strtok(char str[], const char delim[]) {
    static char *ptr = NULL;
    if (str != NULL) {
        ptr = str;
    }
    if (ptr == NULL) {
        return NULL;
    }
    
    //start of the token
    char *start = ptr;
    
    //iterate through the string 
    while (*ptr != '\0') {
        int is_delim = 0;
        //iterate through the delmiter
        for (int i = 0; delim[i] != '\0'; i++) {
            if (*ptr == delim[i]) {
                //replce the delimiter with the null character 
                *ptr = '\0';
                ptr++;
                //is de_lim is true exit the loop 
                is_delim = 1;
                break;
            }
        }
        
        //if it is not a delimiter then move to next character 
        if (!is_delim) {
            ptr++;
        } else if (*start != '\0') {
            return start;
        } else {
            //update start to the current position 
            start = ptr;
        }
    }
    
    //if the start of the token is not a null character 
    if (*start != '\0') {
        return start; //return to the start 
    }
    return NULL; //if no token found return null
}
