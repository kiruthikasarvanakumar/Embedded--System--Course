#include <stdio.h>

int main(){

    //declare te variable
    int n;

    //read the input from the user 
    printf("Enter the Value of 'n' : ");
    scanf("%d", &n);

    if(n % 2 == 0)
    { // Check if 'n' is divisible by 2 
        if (n < 0) 
        {
            // if negative , print the number is negative even number
            printf("%d is negative even number\n", n);
        } 
        else if (n > 0) 
        {
            // if positive , print the number is positive even number
            printf("%d is positive even number\n", n);
        } 
        else
        {
            // if the number is equal to zero,not even print the number is neither odd nor even
            printf("%d is neither odd nor even\n", n);
        }
    }
        else 
        { 
            if (n < 0)
            {
              // if the number is negative , print number is negative odd number
              printf("%d is negative odd number\n",n);
            }     
            else
            {
              //// if positive , print the number is positive odd number
              printf("%d is positive odd number\n",n);
            }
        }
    return 0;
}
