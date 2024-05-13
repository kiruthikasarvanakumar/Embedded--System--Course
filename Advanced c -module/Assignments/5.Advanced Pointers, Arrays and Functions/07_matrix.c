/*
Name : S.Kiruthika
Date : 29-04-2024
Description :  WAP to find the product of given matrix.
Sample input : Enter number of rows : 3
               Enter number of columns : 3
               Enter values for 3 x 3 matrix :
               1      2      3
               1      2      3
               1      2      3
               Enter number of rows : 3
               Enter number of columns : 3
               Enter values for 3 x 3 matrix :
               
               1      1     1
               2      2     2
               3      3     3

Sample output :Product of two matrix :
               14      14      14
               14      14      14
               14      14      14
*/
#include <stdio.h>
#include <stdlib.h>

// Function prototype for matrix multiplication
void matrix_mul(int **, int, int, int **, int, int, int **);

int main() {
    // Declare pointers
    int **mat_a, **mat_b, **result;
    // Declare variables 
    int rows1, cols1, rows2, cols2;

    // Input for matrix 1
    printf("Enter number of rows : ");
    scanf("%d", &rows1);
    printf("Enter number of columns : ");
    scanf("%d", &cols1);

    // Allocate memory for matrix 1
    mat_a = (int **)malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++) {
        mat_a[i] = (int *)malloc(cols1 * sizeof(int));
    }

    printf("Enter values for %d x %d matrix :\n", rows1, cols1);
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            scanf("%d", &mat_a[i][j]);
        }
    }
    
    // Input for matrix 1
    printf("Enter number of rows : ");
    scanf("%d", &rows2);
    printf("Enter number of columns : ");
    scanf("%d", &cols2);
    
    //check if multiplication is possible
    if (cols1 != rows2) {
        printf("Matrix multiplication is not possible\n");
        return 0;
    }

    // Allocate memory for matrix 2
    mat_b = (int **)malloc(rows2 * sizeof(int *));
    for (int i = 0; i < rows2; i++) {
        mat_b[i] = (int *)malloc(cols2 * sizeof(int));
    }

    //input values for matrix 2
    printf("Enter values for %d x %d matrix :\n", rows2, cols2);
    printf("\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            scanf("%d", &mat_b[i][j]);
        }
    }

        //// Allocate memory for result matrix
        result = (int **)malloc(rows1 * sizeof(int *));
        for (int i = 0; i < rows1; i++) {
            result[i] = (int *)malloc(cols2 * sizeof(int));
        }

        //call function
        matrix_mul(mat_a, rows1, cols1, mat_b, rows2, cols2, result);
        printf("Product of two matrix :\n");
        for (int i = 0; i < rows1; i++) {
            for (int j = 0; j < cols2; j++) {
                printf("%d\t", result[i][j]);
            }
            printf("\n");
        }

    // Free allocated memory
    for (int i = 0; i < rows1; i++) {
        free(mat_a[i]);
    }
    free(mat_a);

    for (int i = 0; i < rows2; i++) {
        free(mat_b[i]);
    }
    free(mat_b);

    for (int i = 0; i < rows1; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}

//function to perform matrix multiplication
void matrix_mul(int **mat_a, int rows1, int cols1, int **mat_b, int rows2, int cols2, int **result) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat_a[i][k] * mat_b[k][j];
            }
        }
    }
}
