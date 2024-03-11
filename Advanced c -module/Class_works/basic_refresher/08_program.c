#include <stdio.h>

int main(){
    
    int num;
    
    printf("Enter the number : ");
    scanf("%d", &num);
    
    if (num>=0){
    for (int i=0;i<=num;i++){
       printf("%d ",1<<i);
    }
     printf("\n");
  }else{
      printf("Error : Number should be an positive number.\n");
  }
  return 0;
}
