/*
Name : S.Kiruthika
Date : 30-04-2024
Description :  WAP to define a macro swap (t, x, y) that swaps 2 arguments of type t
Sample input : 1. Int
               2. char
               3. short
               4. float
               5. double
               6. string
Enter you choice : 1

Sample output : Enter the num1 : 10
                Enter the num2 : 20
                After Swapping :
                num1 : 20
                num2 : 10
*/
#include <stdio.h>

// Macro to swap two variables of type t
#define swap(t, x, y) \
    do { \
        t temp = x; \
        x = y; \
        y = temp; \
    } while(0)

int main() {
    int choice;
    //user to enter the choice
    printf("1. Int\n");
    printf("2. char\n");
    printf("3. short\n");
    printf("4. float\n");
    printf("5. double\n");
    printf("6. string\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) 
    {
        case 1: 
        {
            //for integer
            int num1, num2;
            printf("\n");
            printf("Enter the num1 : ");
            scanf("%d", &num1);
            printf("Enter the num2 : ");
            scanf("%d", &num2);
            printf("Before Swapping:\nnum1 : %d\nnum2: %d\n", num1, num2);
            
            //call the swap macro for integers
            swap(int, num1, num2);
            printf("After Swapping:\nnum1 : %d\nnum2: %d\n", num1, num2);
            break;
        }
        case 2: 
        {
            //for character type
            char ch1, ch2;
            printf("Enter the char1: ");
            scanf(" %c", &ch1);
            printf("Enter the char2: ");
            scanf(" %c", &ch2);
            printf("Before Swapping:\nchar1: %c\nchar2: %c\n", ch1, ch2);
            swap(char, ch1, ch2);
            printf("After Swapping:\nchar1: %c\nchar2: %c\n", ch1, ch2);
            break;
        }
        // Similar cases for other types
        default:
            printf("Invalid choice\n");
    }

    return 0;
}
