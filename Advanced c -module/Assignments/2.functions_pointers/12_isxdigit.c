/*
Name : S.Kiruthika
Date : 25-3-2024
Description : WAP to implement your own isxdigit() function
Sample input : Enter the character: a
Sample output : Entered character is not an hexadecimal digit
*/

#include <stdio.h>

//function prototype
int is_xdigit(int);

int main()
{
    char ch;
    short ret;
    
    //read the input from the user
    scanf("%c", &ch);
    
    //call the function
    ret = is_xdigit(ch);
    
    
     if ( ret == 1 )
    {
        //if the return value is 1 , print hexadecimal digit
	printf("Entered character is an hexadecimal digit\n");
    }
    else
    {
        //if the return value is not 1 , print not an hexadecimal digit
	printf("Entered character is not an hexadecimal digit\n");
    }
}

int is_xdigit(int ch)                                                         
{
    // checking hexadecimal digit
    if ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'F') || (ch >= 'a' && ch <= 'f')) {
	return 1;
    }
    else
    {
	return 0;
    }
}
