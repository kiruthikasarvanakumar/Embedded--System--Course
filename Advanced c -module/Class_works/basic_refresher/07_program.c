#include <stdio.h>

int main() {

//initialize a operator using 'char' format specifier
char operator;

//initialize a num1 and num2 using 'double'
double num1,num2;

//read the operator from the user
printf("Enter the Two numbers: ");
scanf("%lf %lf", &num1, &num2);

//read num1 and num2 from the user
printf("Enter the operator: ");
scanf(" %c", &operator);

 double result;
  //for multiple operations use case statements
 switch(operator) {
    case '+':
         result = num1  + num2;
         printf("The Result is : %d\n", (int)result);
         break;
    case '-':
         result = num1 - num2;
         printf("The Result is : %d\n", (int)result);
         break;
    case 'x':
         result = num1 * num2;
         printf("The Result is : %d\n", (int)result);
         break;
    case '/':
       //check if the num2 is 0
       if (num2==0)
        //if num2 is zero print an error message cannot divided by zero
        printf("Error!cannot divided by zero.\n");
      else{
          result = num1 / num2;
          printf("The Result is : %d\n", (int)result);
      }
      break;
    default:
     printf("Invalid Operator.\n");
  }
return 0 ;
}
