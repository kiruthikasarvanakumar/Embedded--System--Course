/*
Name : S.Kiruthika
Date : 08-04-2024
Description :  WAP to implement getword function
Sample input : Enter the string : Welcome to Emertxe
Sample output : You entered Welcome and the length is 7

*/
#include <stdio.h>

int getword(char str[]);

int main()
{
        int len = 0;
	    char str[100];

        //read the input from the user
		printf("Enter the string : ");
		scanf(" %[^\n]", str);

	   len = getword(str);
    
        //print only first word
        printf("You entered %.*s and the length is %d\n",len, str, len);
        return 0;
}
int getword(char str[]) {
    // Calculate length of the first word
    int i = 0;
    while (str[i] != '\0' && str[i] != ' ') {
        i++;
    }
    return i;
}
