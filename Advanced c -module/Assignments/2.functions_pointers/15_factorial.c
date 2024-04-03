/*
Name : S.Kiruthika
Date : 03-04-2024
Description : WAP to find factorial of given number using recursion
Sample input : Enter the value of N : 7
Sample output : Factorial of the given number is 5040

*/
#include <stdio.h>

//function prototype
unsigned long long int factorial(int num);

int main() {
    int num;
    unsigned long long int fact = 1;

    //read the input from the user
    printf("Enter the value of N: ");
    scanf("%d", &num);

    //check if the number is negative
    if (num < 0) {
        //if negative print invalid input
        printf("Invalid Input\n");
        
        //if non-negative,calculate factorial
    } else {
        fact = factorial(num);
        printf("Factorial of the given number is: %llu\n", fact);
    }

    return 0;
}

//function to calculate factorial
unsigned long long int factorial(int num) {
    unsigned long long int fact = 1;
    for (int i = 1; i <= num; i++) {
        fact *= i;
    }
    return fact;
}
