#include <stdio.h>

int main() {
    int num, flag = 0;
    printf("Enter a number: ");
    scanf("%d", &num);

    
    if (num <= 1) {
        printf("Invalid input\n");
        return 0;
    }

    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        printf("is a prime number\n");
    } else {
        printf("is not a prime number\n");
    }

    return 0;
}
