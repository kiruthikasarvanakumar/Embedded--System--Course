/*
Name : S.Kiruthika
Date : 17-04-2024
Description : Generate consecutive NRPS of length n using k distinct character
Sample input : Enter the number characters C : 3
               Enter the Length of the string N : 6
               Enter 3 distinct characters : a b c
Sample output : Possible NRPS is abcbca

*/
#include <stdio.h>

void generate_nrps(char chars[], int n, int k);

int main() {
    int n, k;
    
    //read the input from the user
    printf("Enter the number characters C : ");
    scanf("%d", &k);
    printf("Enter the length of the string N : ");
    scanf("%d", &n);

    char distinct_chars[k];
    printf("Enter %d distinct characters : ", k);

    // Read distinct characters
    for (int i = 0; i < k; i++) {
        // space before %c to consume newline
        scanf(" %c", &distinct_chars[i]); 
    }

    // Check if characters are distinct
    int valid_input = 1; // Assume input is valid
    for (int i = 0; i < k - 1; i++) {
        for (int j = i + 1; j < k; j++) {
            if (distinct_chars[i] == distinct_chars[j]) {
                // Input is not valid
                valid_input = 0; 
                break;
            }
        }
        if (!valid_input) {
            break;
        }
    }

    if (!valid_input) {
        printf("Error : Enter distinct characters\n");
        return 1; 
    }

    generate_nrps(distinct_chars, n, k);

    return 0;
}

void generate_nrps(char chars[], int n, int k) {
    int i, j;
    int count = 0;

    // Output NRPS
    printf("Possible NRPS is ");
    while (count < n) {
        for (i = 0; i < k && count < n; i++) {
            printf("%c", chars[i]);
            count++;
        }
        for (j = k - 1; j >= 0 && count < n; j--) {
            printf("%c", chars[j]);
            count++;
        }
    }
    printf("\n");
}
