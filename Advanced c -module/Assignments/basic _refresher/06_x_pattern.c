#include <stdio.h>

int main() {

    //declare avariable
    int num;
    // read a number from the user
    printf("Enter the number: ");
    scanf("%d", &num);
    
    //run a loop for row
    for (int i = 1; i <= num; i++) {

        //run a loop forcolumn
        for (int j = 1; j <= num; j++) {

            //check i equal to j or i + j is equal to num + 1
            if (i == j || i + j == num + 1) {

                //if yes print the number
                printf("%d", j);
            } else {

                //if no print space
                printf("  "); 
            }
        }
        printf("\n");
    }

    return 0;
}
