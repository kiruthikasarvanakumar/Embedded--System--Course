/*
Name : S.Kiruthika
Date : 29-04-2024
Description :  Read n & n person names of maxlen 20. Sort and print the names
Sample input : Enter the size: 5

               Enter the 5 names of length max 20 characters in each
               [0] -> Delhi
               [1] -> Agra
               [2] -> Kolkata
               [3] -> Bengaluru
               [4] -> Chennai
Sample output :The sorted names are:
               Agra
               Bengaluru
               Chennai
               Delhi
               Kolkata
*/
#include <stdio.h>
#include <stdlib.h>

void sort_names(char (*)[20], int);
int my_strcmp(char *, char *); 
void my_strcpy(char *, char *); 

int main() {
    int size;
    printf("Enter the size: ");
    scanf("%d", &size);

    // Allocate memory for array of strings
    char (*arr)[20] = malloc(size * sizeof(*arr)); 

    printf("\nEnter %d names of length max 20 characters in each \n", size);
    for (int i = 0; i < size; i++) {
        printf("[%d] -> ", i);
        // Read each string into the array
        scanf(" %s", arr[i]); 
    }

    sort_names(arr, size); // Call the sorting function

    // sorting the output strings
    printf("\nThe sorted names are:\n");
    for (int i = 0; i < size; i++) {
        printf("%s\n", arr[i]);
    }

    // Free allocated memory
    free(arr);

    return 0;
}

//string comparison function
int my_strcmp(char *s1, char *s2) {
    while (*s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

//string copy function
void my_strcpy(char *dest, char *src) {
    while (*src) {
        *dest = *src;
        src++;
        dest++;
    }
    // Null-terminate the destination string
    *dest = '\0'; 
}

// Sorting function using string comparison
void sort_names(char (*arr)[20], int size) {
    char temp[20];

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (my_strcmp(arr[j], arr[j + 1]) > 0) {
                // Swap the strings
                my_strcpy(temp, arr[j]);
                my_strcpy(arr[j], arr[j + 1]);
                my_strcpy(arr[j + 1], temp);
            }
        }
    }
}
