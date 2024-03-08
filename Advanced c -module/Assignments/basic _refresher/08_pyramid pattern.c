#include <stdio.h>

int main() {
    int num;

    // user to enter the number
    printf("Enter the number: ");
    scanf("%d", &num);

    // Printing the upper half of the pyramid pattern
    for (int i = num; i >= 1; i--) {
        for (int j = i; j <= num; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
    
    // Printing the lower half of the pyramid pattern
    for (int i = 2; i <= num; i++) {
        for (int j = i; j <= num; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }

    return 0;
}
