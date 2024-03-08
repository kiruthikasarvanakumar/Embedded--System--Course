#include <stdio.h>
int main(){
    
    //variable declaration
    int temp=0,A,R,N,i;
    int ap,gp;
    float hp;
    printf("Enter the First Number 'A': ");
    scanf("%d",&A);
    printf("Enter the Common Difference / Ratio 'R': ");
    scanf("%d", &R);
    printf("Enter the number of terms 'N': ");
    scanf("%d", &N);
    if(N >= 1) // checking the number positive or not
    {
        //arithmetic progression
        printf("AP = ");
        ap = A;
        printf("%d", ap);
             
             //run a loop for n times
             for (i=1;i<N;i++){
                ap=ap+R;
                printf(",%d", ap);
             }
             printf("\n");
             
        // Geometric Progression (GP)
        printf("GP = ");
        //Initialize GP term
        gp = A;
        // Temporary variable to calculate GP term
        temp=1;
        printf("%d", gp);
            // Loop to calculate and print subsequent terms
            for (i=1;i<N;i++){
              temp=temp*R;
              gp=A*temp;
              printf(",%d", gp);
             }
             printf("\n");
             
        //Harmonic progression (HP)
        printf("HP = ");
        //Initialize HP term
        ap = A;
        hp = 1.0/A;
        printf("%f", hp);
            // Loop to calculate and print subsequent terms
            for (i=1;i<N;i++){
              ap=ap+R;
              hp=1.0/ap;
              printf(",%f", hp);
            }
            printf("\n");
    }else{
       // Print error message for invalid input
       printf("Invalid input\n");
    }
return 0;
}
