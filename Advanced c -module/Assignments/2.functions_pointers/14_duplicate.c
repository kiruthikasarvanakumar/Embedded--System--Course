/*
Name : S.Kiruthika
Date : 02-04-2024
Description : WAP to remove duplicate elements in a given array
Sample input : Enter the size: 5
               Enter elements into the array: 5 1 3 1 5
Sample output : After removing duplicates: 5 1 3
*/
#include <stdio.h>

void fun(int arr[], int size, int *new_size);

int main() {
    int size;
    
    // Read the size of the array
    printf("Enter the size: ");
    scanf("%d", &size);
    
    int arr[size];
    
    // Read elements into the array
    printf("Enter elements into the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Remove duplicates
    int new_size;
    fun(arr, size, &new_size);
    
    // Print the array after removing duplicates
    printf("After removing duplicates: ");
    for (int i = 0; i < new_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}

// Function definition
void fun(int arr[], int size, int *new_size) {
    // Initialize new size of the array
    *new_size = 0;
    
    // run a loop for the original array
    for (int i = 0; i < size; i++) {
        int duplicate = 0;
        
        // run a loop for the duplicate elements
        for (int j = 0; j < *new_size; j++) {
            if (arr[i] == arr[j]) {
              //if duplicate is found out of the loop
                duplicate = 1;
                break;
            }
        }
        //if not duplicate add to the array
        if (!duplicate) {
            arr[*new_size] = arr[i];
            (*new_size)++;
        }
    }
}
