#include <stdio.h>
int main (){
    
    //declare a variable
    int num,sum=0;
    
    //user to enter a number and read the number
    printf("Enter a number: ");
    scanf("%d" ,&num);
    
    //Check if the entered number is positive
    if(num > 0){
        
        //Loop to find the sum of proper divisors of the number
        for(int i=1;i<num;i++){
            if (num % i == 0) {
            sum=sum+i;        
        }
    }
    if (sum == num) {
            printf("Yes, entered number is perfect number\n");
        } else {
            printf("No, entered number is not a perfect number\n");
        }
    } else{
        printf("Error : Invalid Input, Enter only positive number\n");
    }


}
