/*
Name : S.Kiruthika
Date : 25-3-2024
Description : WAP to implement your own ispunct() function
Sample input : Enter the character: a
Sample output : Entered character is not an punctuation character
*/

#include <stdio.h>

//function prototype
int my_ispunct(char);

int main()
{
    char ch;
    int ret;
    
    //read the input from the user
    scanf("%c", &ch);
    
    //call the function
    ret = my_ispunct(ch);
    
    
     if ( ret == 1 )
    {
        //if the return value is 1 , print punctuation character
	printf("Entered character is punctuation character\n");
    }
    else
    {
        //if the return value is not 1 , print not an punctuation character
	printf("Entered character is not punctuation character\n");
    }
}

int my_ispunct(char ch)                                                         
{
    // checking punctuation character
    if ((ch >= '!' && ch <= '/') || (ch >= ':' && ch <= '@') || (ch >= '[' && ch <= '`') || (ch >= '{' && ch <= '~')) {
	return 1;
    }
    else
    {
	return 0;
    }
}
