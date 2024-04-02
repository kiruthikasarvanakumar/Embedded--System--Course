/*
Name : S.Kiruthika
Date : 25-3-2024
Description : WAP to find 2nd largest element in an array
Sample input : Enter the size of the Array : 5
               Enter the elements into the array: 5 1 4 2 8
Sample output : Second largest element of the array is 5
*/
#include <stdio.h>

//function prototype
int sec_largest(int *, int);  

int main()
{
    int size, ret;
    
    // Read size from the user
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int arr[size];
    
    // Read elements into the array
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Function call to find the second largest element
    ret = sec_largest(arr, size);
    
    printf("Second largest element of the array is %d\n", ret);
}

// Function definition to find the largest element in an array
int find_largest(int arr[], int size) {
    int largest = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    return largest;
}

// Function definition to find the smallest element in an array
int find_smallest(int arr[], int size) {
    int smallest = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }
    return smallest;
}

// Function definition to find the second largest element in an array
int sec_largest(int arr[], int size) {
    int largest = find_largest(arr, size);
    int smallest = find_smallest(arr, size);
    int secondLargest = smallest; 
    
    // array to find the second largest element
    for (int i = 0; i < size; i++) {
        if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}
