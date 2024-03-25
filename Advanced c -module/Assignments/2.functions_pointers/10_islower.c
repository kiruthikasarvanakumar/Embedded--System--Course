/*
Name : S.Kiruthika
Date : 25-3-2024
Description : WAP to implement your own islower() function
Sample input : Enter the character: a
Sample output : Entered character is an lower case alphabet.
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
        //if the return value is 1 , print lower alphabet
	printf("Entered character is lower case alphabet\n");
    }
    else
    {
        //if the return value is not 1 , print not an lower alphabet
	printf("Entered character is not lower case alphabet\n");
    }
}

int my_isalnum(char ch)                                                         
{
    // checking lower case character 
    if ((ch >= 'a' && ch <= 'z')) {
	return 1;
    }
    else
    {
	return 0;
    }
}
