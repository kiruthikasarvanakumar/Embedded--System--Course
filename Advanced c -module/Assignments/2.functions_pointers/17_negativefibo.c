/*
Name : S.Kiruthika
Date : 03-04-2024
Description : WAP to generate negative fibbonacci numbers using recursion
Sample input : Enter a number: -8
Sample output : 0, 1, -1, 2, -3, 5, -8

*/
#include <stdio.h>

// Function prototype
void negative_fibonacci(int limit, int first, int second, int next);

int main()
{
    int limit;
    
    printf("Enter a  number: ");
    scanf("%d", &limit);

        if (limit > 0) {
        printf("Invalid input\n");
    } else {
        // Starting the Fibonacci sequence with 0 and 1
        negative_fibonacci(limit, 0, 1, 0);
    }
    
    return 0;
}

// function prototype
void negative_fibonacci(int num, int first, int second, int next)       

{
    // to generate the negative fibonacci series
    while( next >= num && next <= (-num))	                     
    {
         printf("%d, ",next);
	     first=second;
	     second=next;
	     next=first-second;	 
    }
    printf("\n");
}
