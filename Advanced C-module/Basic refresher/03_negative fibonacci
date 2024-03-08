#include <stdio.h>
int main (){
    
    //declare a variable
    int num,first=0,second=1,next;
    
    //user to enter a number and read a number entered by the user
    printf("Enter a number: ");
    scanf("%d", &num);

    //check if the number is negative
    if(num <= 0) {
        
        //print first two fibonacci numbers
        printf("%d ", first);
        printf("%d ", second);
        //calculate next fibonacci
        next = first - second;
        
        //loop to print Fibonacci numbers until they exceed the entered number
        while(next >= num){
            printf("%d ", next);
            first=second;
            second=next;
            next=first-second;
        }
        printf("\n");
    }
    else{
        // If the entered number is positive, print an error message
        printf("Invalid input\n");
    }
  return 0;
}
