/*
Name : S.Kiruthika
Date : 27-04-2024
Description : WAP to implement fragments using Array of Pointers
Sample input : Enter no.of rows : 3
               Enter no of columns in row[0] : 4
               Enter no of columns in row[1] : 3
               Enter no of columns in row[2] : 5
               Enter 4 values for row[0] : 1 2 3 4
               Enter 3 values for row[1] : 2 5 9
               Enter 5 values for row[2] : 1 3 2 4 1

Sample output : Before sorting output is:

                1.000000 2.000000 3.000000 4.000000 2.500000

                2.000000 5.000000 9.000000 5.333333

                1.000000 3.000000 2.000000 4.000000 1.000000 2.200000

                After sorting output is:

                1.000000 3.000000 2.000000 4.000000 1.000000 2.200000

                1.000000 2.000000 3.000000 4.000000 2.500000

                2.000000 5.000000 9.000000 5.333333
*/
#include<stdio.h>
#include<stdlib.h>

// Function prototype 
void sort_by_average(float **, int *, int);                                      
void print(float **, int *, int);                                                 


int main() {
    int n;
    // read the number of rows from the user
    scanf("%d", &n);	                         

    // Array to store the number of columns in each row
    int row[n];                                                                      
    // Array of pointers
    float *array[n];                                                                 
    

    for(int i = 0; i < n; i++) {
        // Reading the number of columns in each row
        scanf("%d", &row[i]);                                                        
         // Dynamically allocating memory for every row
        array[i] = (float *)malloc(row[i] * sizeof(float));                          
       
    }

    for(int i = 0; i < n; i++) {
        // Reading column values
        for(int j = 0; j < row[i]; j++) {
            scanf("%f", &array[i][j]);                                               
            
        }
    }
    // Loop to calculate and store average value
    for(int i = 0; i < n; i++) {                                                     
        float sum = 0;
        for(int j = 0; j < row[i]; j++) {
            // Sum of all elements of each row
            sum += array[i][j];                                                      
            
        }
        // Calculating the average and storing it in the last element of each row
        array[i][row[i]] = sum / row[i];                                             
        
    }
     
     //function call for printing
    printf("Before sorting output is:\n");
    print(array, row, n);                                                            
    
    // Function call for sorting
    sort_by_average(array, row, n);                                                  
    
       // Function call for printing
    printf("After sorting output is:\n");
    print(array, row, n);                                                            
    

    // Freeing the dynamically allocated memory
    for(int i = 0; i < n; i++) {
        free(array[i]);
    }

    return 0;
}

void sort_by_average(float **array, int *row, int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            // Compare by the average values
            if(array[j][row[j]] > array[j + 1][row[j + 1]]) {                        
                float *temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                int temp_row = row[j];
                row[j] = row[j + 1];
                row[j + 1] = temp_row;
            }
        }
    }
}

void print(float **array, int *row, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < row[i]; j++) {
            printf("%.6f ", array[i][j]);
        }
        printf("%.6f\n", array[i][row[i]]);
    }
}
