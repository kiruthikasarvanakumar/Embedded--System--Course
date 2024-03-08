#include <stdio.h>

int main() {
    int num;
    printf("Enter the value of 'n': ");
    scanf("%d", &num);

    if (num <= 1) {
        printf("Please enter a positive number which is > 1\n");
        return 0;
    }

    // Initialize an array to mark prime numbers
    int arr[num];
    for (int i = 0; i < num; i++) {
        arr[i] = 1;
    }

    // Use Sieve of Eratosthenes algorithm
    for (int i = 2; i * i <= num; i++) {
        if (arr[i] == 1) {
            for (int j = i * i; j <= num; j += i) {
                
                // Mark multiples of prime i as non-prime
                arr[j] = 0; 
            }
        }
    }

    // Print prime numbers
    printf("The primes less than or equal to %d are : ", num);
    
    // Initialize printed count
    int printed = 0; 
    for (int i = 2; i <= num; i++) {
        if (arr[i] == 1) {
            if (printed > 0) {
                // Print comma if not the first prime
                printf(", "); 
            }
            // Print the prime number
            printf("%d", i);
            
            // Increment printed count
            printed++; 
        }
    }
    printf("\n");

    return 0;
}
