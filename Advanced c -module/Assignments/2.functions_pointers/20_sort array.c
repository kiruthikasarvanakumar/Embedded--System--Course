/*
Name : S.Kiruthika
Date : 06-04-2024
Description : Print the values in sorted order without modifying or copying array
Sample input : Enter the size : 7
               Enter 7 elements 
               1 3 2 5 4 7 6
Sample output :  After sorting: 1 2 3 4 5 6 7
                 Original array values 1 3 2 5 4 7 6

*/
#include <stdio.h>

void print_sort(int [], int);

int main()
{
    int size, iter;
    
    printf("Enter the size: ");
    scanf("%d", &size);
    
    int arr[size];
    
    printf("Enter %d elements\n ", size);
    for (iter = 0; iter < size; iter++)
    {
        scanf("%d", &arr[iter]);
    }

    // Sorting the array
    int sorted_arr[size];
    for (iter = 0; iter < size; iter++)
    {
        sorted_arr[iter] = arr[iter];
    }
    // Print the sorted array
    print_sort(sorted_arr, size);  

    printf("Original array values ");
    for (iter = 0; iter < size; iter++)
    {
        printf("%d ", arr[iter]);
    }
    printf("\n");
    
    return 0;
}
    
void print_sort(int arr[], int size)
{
    // Bubble Sort
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap without modifying the array
                arr[j] = arr[j] + arr[j + 1];
                arr[j + 1] = arr[j] - arr[j + 1];
                arr[j] = arr[j] - arr[j + 1];
            }
        }
    }
    
    // Printing the sorted array
    printf("After sorting: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
