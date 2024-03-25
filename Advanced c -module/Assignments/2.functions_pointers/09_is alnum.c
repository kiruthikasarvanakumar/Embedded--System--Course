/*
Name : S.Kiruthika
Date : 25-3-2024
Description : WAP to implement your own isalnum() function
Sample input : Enter the character: a
Sample output : The character 'a' is an alnum character.
*/
#include <stdio.h>

//function prototype
int my_isalnum(char);

int main()
{
    char ch;
    int ret;
    
    //read the input from the user
    scanf("%c", &ch);
    
    //call the function
    ret = my_isalnum(ch);
    
    
     if ( ret == 1 )
    {
        //if the return value is 1 , print alphanumeric character
	printf("Entered character is alphanumeric character");
    }
    else
    {
        //if the return value is not 1 , print not an alphanumeric character
	printf("Entered character is not alphanumeric character\n");
    }
}

int my_isalnum(char ch)                                                         
{
    // Using bitwise AND for checking alphanumeric characters
    if ((ch >= 'A' & ch <= 'Z') || (ch >= 'a' & ch <= 'z') || (ch >= '0' & ch <= '9')) {
	return 1;
    }
    else
    {
	return 0;
    }
}
