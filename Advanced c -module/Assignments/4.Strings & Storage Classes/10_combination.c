/*
Name : S.Kiruthika
Date : 18-04-2024
Description : WAP to print all possible combinations of given string.
Sample input : Enter a string: abc
Sample output : All possible combinations of given string :abc
                acb
                bca
                bac
                cab
                cba

*/
#include<stdio.h>

void combination(char *, int, int);
int my_strlen(char *);
void swap(char *, char *);

int main() {
    char str[100];
    int n;

    printf("Enter a string: ");
    scanf("%99[^\n]", str); 
    n = my_strlen(str);

    // Check if all characters in the string are distinct
    int distinct = 1;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (str[i] == str[j]) {
                distinct = 0;
                break;
            }
        }
        if (!distinct) {
            printf("Error: Please enter distinct characters.\n");
            return 0;
        }
    }

    printf("All possible combinations of given string :");
    combination(str, 0, n - 1);

    return 0;
}

//function definition for my_strlen()
int my_strlen(char *str)                                                        
{
    int i;
    int count = 0;                                                              
    for( i = 0; str[i] != '\0'; i++)
    {
	count++;                                                                
    }
    return count;                                                               
}

//function definition for swap()
void swap(char *x, char *y)	      	                                        
{
    char temp;                                                                 
    temp = *x;
    *x = *y;
    *y = temp;
}

//function definition for combination()
void combination(char *str, int start, int end)                                  
{
    int n;

    //condition to print the string
    if (start == end)                                               
    {    
	printf("%s\n", str);
    }
    else
    {
	for (int n = start; n <= end; n++)
	{
                //swapping and fixing one index value at a time
	    swap((str + start), (str + n));                              

            //recursive function call with incremented index position
	    combination(str, start + 1, end);            

	    swap((str + start), (str + n));                              
	}
    }
}


