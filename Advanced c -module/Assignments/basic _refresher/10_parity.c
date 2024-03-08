#include <stdio.h>
int main(){
    
    //declare the variable
    int num,count=0;
    
    //read the input from the user
    printf("Enter the number: ");
    scanf("%d", &num);
    
    //count no.of set bits in num
    //run a loop for 32 times
    for(int i=0;i<32;i++){
        if (num & (1 << i)){
            count=count+1;
        }
    }
    printf("Number of set bits = %d\n", count);
    
    //check the parity is odd or even based on the number of set bits
    if ((count%2)==0)
    {
        printf("Bit parity is Even\n");
    }
    else{
        printf("Bit parity is odd\n");
    }
    
}
