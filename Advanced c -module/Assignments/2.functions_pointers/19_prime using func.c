/*
Name : S.Kiruthika
Date : 04-04-2024
Description : WAP to generate the prime series upto the given limit using functions
Sample input : Enter a number: 2
Sample output : 2 

*/
#include <stdio.h>

int is_prime(int);

void generate_prime(int);

int main()
{
    int limit;
    
    printf("Enter a number: ");
    scanf("%d", &limit);
    
    if (limit > 1)
    {
        generate_prime(limit);
    }
    else
    {
        

        printf("Invalid input\n");
    }
    
    return 0;
}
// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1)
        
        // Not prime
        return 0; 
        
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
        
        // Not prime
            return 0; 
    }
    
    // Prime
    return 1; 
}

// Function to generate prime numbers up to a given limit
void generate_prime(int limit) {
    
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i))
            printf("%d ", i);
    }
    printf("\n");
}
