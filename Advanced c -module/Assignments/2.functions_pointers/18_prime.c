/*
Name : S.Kiruthika
Date : 04-04-2024
Description : WAP to check whether a given number is prime or not using function.
Sample input : Enter a number: 2
Sample output : 2 is a prime number

*/

#include <stdio.h>

int is_prime(int);

int main() {
    int num;

    
     scanf("%d", &num);
     
     //to check negative numbers
     if (num < 0) {
        printf("Invalid input\n");
        return 1; 
    }
    int res = is_prime(num);

    if (res == 1) {
        printf("%d is a prime number\n", num);
    } else {
        printf("%d is not a prime number\n", num);
    }

    return 0;
}

// Numbers less than or equal to 1 are not prime
int is_prime(int num) {
    if (num <= 1) {
        return 0; 
    }

    // If num is divisible by any number from 2 to sqrt(num), it's not prime
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; 
        }
    }

    // If none of the above conditions met, it's prime
    return 1; 
}
