#include<stdio.h>

int main() {
    int dayOfYear, firstDayOfWeek, remainingDays, choice;

    // Read the day of the year
    scanf("%d", &dayOfYear);

    // Check if the day of the year is within valid range (1 to 365)
    if(dayOfYear > 0 && dayOfYear <= 365) {
        // Read the user's choice for the first day of the week
        scanf("%d", &firstDayOfWeek);

        // Check if the chosen first day is within valid range (1 to 7)
        if(firstDayOfWeek > 0 && firstDayOfWeek <= 7) {
            remainingDays = (7 - firstDayOfWeek) + 1;
            choice = dayOfYear - remainingDays;

            // checking condition for negative value
            if(choice < 0)
                choice = (dayOfYear + firstDayOfWeek) - 1;

            // checking condition when extra is 0 or exceeds 7
            if(choice == 0)
                choice = 7;
            if(choice > 7)
               choice = choice % 7;

            // Using a switch statement
            switch(choice) {
                case 1:
                    printf("The day is Sunday\n");
                    break;
                case 2:
                    printf("The day is Monday\n");
                    break;
                case 3:
                    printf("The day is Tuesday\n");
                    break;
                case 4:
                    printf("The day is Wednesday\n");
                    break;
                case 5:
                    printf("The day is Thursday\n");
                    break;
                case 6:
                    printf("The day is Friday\n");
                    break;
                case 7:
                    printf("The day is Saturday\n");
                    break;
            }
        } else {
            printf("Error: Invalid input, first day should be > 0 and <= 7\n");
        }
    } else {
        printf("Error: Invalid Input, n value should be > 0 and <= 365\n");
    }

    return 0;
}
