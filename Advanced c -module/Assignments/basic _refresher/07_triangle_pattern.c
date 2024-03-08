#include<stdio.h>

int main()
{
    // variable declaration
    int num, i, j, digit = 0; 

    // read a number from the user
    printf("Enter the number: ");
    scanf("%d", &num); 

    //Run a loop for rows
    for(i = num; i >= 1; i--) 
    {
        // Run a loop for columns
        for(j = i; j >= 1; j--) 
        {
            
            // Check if i equals num or j equals i or j equals 1
            if(i == num || j == i || j == 1) 
            {

                digit = digit + 1; 

                printf("%d ", digit);
            }
            else
                printf(" "); 

        }
        printf("\n"); 
    }

    return 0;
}
