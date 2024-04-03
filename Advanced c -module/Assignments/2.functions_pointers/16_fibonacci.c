/*
Name : S.Kiruthika
Date : 03-04-2024
Description : WAP to generate fibbonacci numbers using recursion
Sample input : Enter a number: 8
Sample output : 0, 1, 1, 2, 3, 5, 8

*/
#include <stdio.h>

// Function prototype
void positive_fibonacci(int limit, int first, int second, int next);

int main()
{
    int limit;
    
    printf("Enter the limit : ");
    scanf("%d", &limit);
    
    if (limit < 0) {
        printf("Invalid input\n");
    } else {
        // Starting the Fibonacci sequence with 0 and 1
        positive_fibonacci(limit, 0, 1, 0);
    }
    
    return 0;
}

// Function to generate and print Fibonacci series up to a given limit
void positive_fibonacci(int limit, int first, int second, int next) {
    
    // Printing initial values
    printf("%d, %d", first, second);
    
    // while loop
    while (next <= limit) {
        next = first + second;
        
        // Check if next Fibonacci number exceeds the limit
        if (next <= limit) {
            printf(", %d", next);
        }
        
        // Update variables for next iteration
        first = second;
        second = next;
    }
    
    printf("\n");
}
