/*
Name : S.Kiruthika
Date : 02-04-2024
Description : Provide a menu to manipulate or display the value of variable of type t
Sample input : Menu :
1. Add element
2. Remove element
3. Display element
4. Exit from the program

Choice ---> 1
Enter the type you have to insert:
1. int
2. char
3. float
4. double
Choice ---> 2
Enter the char : k
1. Add element
2. Remove element
3. Display element
4. Exit from the program
Choice ---> 3
-------------------------
0 -> k
-------------------------
1. Add element
2. Remove element
3. Display element
4. Exit from the program
Choice ---> 1
Enter the type you have to insert:
1. int
2. char
3. float
4. double
Choice ---> 1
Enter the int : 10
1. Add element
2. Remove element
3. Display element
4. Exit from the program
Choice ---> 3
------------------------
0 -> k (char)
1 -> 10 (int)
------------------------
1. Add element
2. Remove element
3. Display element
4. Exit from the program

Choice ---> 2
0 -> k
1 -> 10
Enter the index value to be deleted : 0
index 0 successfully deleted.
1. Add element
2. Remove element
3. Display element
4. Exit from the program
Choice ---> 4
*/
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void add_element(int type, void *data, char *display[], int *count);
void remove_element(int index, char *display[], int *count);
void display_elements(char *display[], int count);

int main() {
    // Define maximum number of elements
    #define MAX_ELEMENTS 10

    // Array to hold display strings
    char *display[MAX_ELEMENTS] = {0};

    // Variable to keep track of the number of elements
    int count = 0;

    int choice;
    do {
        // Display menu
        if (count == 0) {
            printf("Menu :\n1. Add element\n2. Remove element\n3. Display element\n4. Exit from the program\n\n");
        } else {
            printf("Menu :\n1. Add element\n2. Remove element\n3. Display element\n4. Exit from the program\n\n");
        }

        printf("Choice ---> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (count >= MAX_ELEMENTS) {
                    printf("Maximum number of elements reached.\n");
                    break;
                }

                int type;
                printf("Enter the type you have to insert:\n1. int\n2. char\n3. float\n4. double\nChoice ---> ");
                scanf("%d", &type);

                switch (type) {
                    case 1: {
                        int int_val;
                        printf("Enter the int : ");
                        scanf("%d", &int_val);
                        add_element(type, &int_val, display, &count);
                        break;
                    }
                    case 2: {
                        char char_val;
                        printf("Enter the char : ");
                        scanf(" %c", &char_val);
                        add_element(type, &char_val, display, &count);
                        break;
                    }
                    case 3: {
                        float float_val;
                        printf("Enter the float : ");
                        scanf("%f", &float_val);
                        add_element(type, &float_val, display, &count);
                        break;
                    }
                    case 4: {
                        double double_val;
                        printf("Enter the double : ");
                        scanf("%lf", &double_val);
                        add_element(type, &double_val, display, &count);
                        break;
                    }
                    default:
                        printf("Invalid choice.\n");
                }
                break;
            }
            case 2: {
                if (count == 0) {
                    printf("No elements to remove.\n");
                    break;
                }

                int index;
                printf("Enter the index value to be deleted : ");
                scanf("%d", &index);
                if (index < 0 || index >= count) {
                    printf("Invalid index.\n");
                    break;
                }

                remove_element(index, display, &count);
                printf("index %d successfully deleted.\n", index);
                break;
            }
            case 3: {
                if (count == 0) {
                    printf("No elements to display.\n");
                    break;
                }

                display_elements(display, count);
                break;
            }
            case 4:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void add_element(int type, void *data, char *display[], int *count) {
    // Allocate memory for display string
    display[*count] = (char *)malloc(50 * sizeof(char));
    if (display[*count] == NULL) {
        printf("Memory allocation failed. Unable to add element.\n");
        return;
    }

    // Format the display string based on the type of data
    switch (type) {
        case 1:
            sprintf(display[*count], "%d", *(int *)data);
            break;
        case 2:
            sprintf(display[*count], "%c", *(char *)data);
            break;
        case 3:
            sprintf(display[*count], "%.2f", *(float *)data);
            break;
        case 4:
            sprintf(display[*count], "%.2lf", *(double *)data);
            break;
        default:
            printf("Invalid type.\n");
            free(display[*count]);
            return;
    }

    // Increment the count of elements
    (*count)++;
}

void remove_element(int index, char *display[], int *count) {
    free(display[index]);
    for (int i = index; i < *count - 1; i++) {
        display[i] = display[i + 1];
    }
    (*count)--;
}

void display_elements(char *display[], int count) {
    printf("------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d -> %s\n", i, display[i]);
    }
    printf("------------------------\n");
}

