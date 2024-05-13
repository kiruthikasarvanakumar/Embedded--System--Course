/*
Name : S.Kiruthika
Date : 23-04-2024
Description : Variance calculation with dynamic arrays
Sample input : Enter the no.of elements : 10
Sample output : Enter the 10 elements:
                [0] -> 9
                [1] -> 12
                [2] -> 15
                [3] -> 18
                [4] -> 20
                [5] -> 22
                [6] -> 23
                [7] -> 24
                [8] -> 26
                [9] -> 31
                Variance is 40.000000
*/
#include <stdio.h>

float variance(int *, int);

int main()
{
    int n;
    printf("Enter the no.of elements : ");
    scanf("%d", &n);

    // Declare arrays with variable lengths
    int arr[n];
    float d[n];
    float d_sqr[n];

    // Read elements of the array
    printf("Enter the %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate the mean of the array elements
    float arr_mean = 0;
    for (int i = 0; i < n; i++) {
        arr_mean += arr[i];
    }
    arr_mean /= n;

    // Calculate deviations
    for (int i = 0; i < n; i++) {
        d[i] = arr[i] - arr_mean;
    }

    // Calculate squared deviations
    for (int i = 0; i < n; i++) {
        d_sqr[i] = d[i] * d[i];
    }

    // Call variance function
    float var = variance(arr, n);

    // Print the elements of the array
    for (int i = 0; i < n; i++) {
        printf("[%d] -> %d\n", i, arr[i]);
    }


    printf("\nVariance is %.6f\n", var);

    return 0;
}

float variance(int *arr, int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum = sum + arr[i];
    }
    float mean = sum / n;

    float sum_d_sqr = 0;
    for (int i = 0; i < n; i++) {
        sum_d_sqr = sum_d_sqr + (arr[i] - mean) * (arr[i] - mean);
    }

    return sum_d_sqr / n;
}
