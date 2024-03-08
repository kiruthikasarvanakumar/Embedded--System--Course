#include<stdio.h>

int main()
{
    // variable declaration
    int num, N, M, mask; 

    printf("Enter the number: ");
    // reading the number
    scanf("%d", &num); 

    // reading Nth bit
    printf("Enter 'N': ");
    scanf("%d", &N); 

    // reading Mth bit
    printf("Enter 'M': ");
    scanf("%d", &M); 

    // Check if the Nth bit is set
    if ((num >> N) & 1) {
        // Clear the Mth bit
        num &= ~(1 << M);
        printf("Updated value of num is %d\n", num);
    } else {
        printf("Updated value of num is %d\n",num);
    }

    return 0;
}
