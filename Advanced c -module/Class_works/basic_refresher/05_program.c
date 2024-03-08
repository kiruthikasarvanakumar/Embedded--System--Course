#include <stdio.h>

int main(){
    
    int num1,num2,num3,middle;
    
    printf("Enter the Three numbers : ");
    scanf("%d %d %d", &num1,&num2,&num3);
    
    if((num1 <= num2 && num1 >= num3) || (num1 >= num2 && num1 <= num3)){
        middle = num1;
    }
    else if((num2 <= num1 && num2 >= num3) || (num2 >= num1 && num2 <= num3)){
        middle = num2;
    }
    else{
        middle = num3;
    }
        printf("The middle number is %d\n",middle);
   return 0;
}
