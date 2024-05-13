/*
Name : S.Kiruthika
Date : 26-04-2024
Description : WAP to generate a n*n magic square
Sample input : Enter a number: 3
Sample output : 8      1      6
                3      5      7
                4      9      2
*/
#include <stdio.h>
#include <stdlib.h>

//function prototype for magic_square
void generated_magic_square(int *arr, int n);

int main() {
    int n;
    
    //read the input from the user
    scanf("%d", &n);
    
    //condition to check if user enters positive number
    if (n % 2 == 0) {
        printf("Error : Please enter only positive odd numbers\n");
        return 1;
    }

    int *magic_square = (int *)calloc(n * n, sizeof(int));

    if (magic_square == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    generated_magic_square(magic_square, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%2d ", magic_square[i * n + j]);
        }
        printf("\n");
    }

    // Free dynamically allocated memory
    free(magic_square); 

    return 0;
}

//function defintion
void generated_magic_square(int *arr, int n) {
    int row = 0, col = n / 2;
    
    for (int num = 1; num <= n * n; num++) {
        arr[row * n + col] = num;
        int next_row = (row - 1 + n) % n; 
        int next_col = (col + 1) % n;     
        
        if (arr[next_row * n + next_col] != 0) {
            // Move down one position
            row = (row + 1) % n;
        } else {
            row = next_row;
            col = next_col;
        }
    }
}
