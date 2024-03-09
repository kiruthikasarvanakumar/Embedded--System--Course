/*
Name : S.Kiruthika
Date : 09-3-2024
Description : WAP to find the median of two unsorted arrays
Sample input : Enter the 'n' value for Array A: 5
               Enter the 'n' value for Array B: 5
               Enter the elements one by one for Array A: 3 2 8 5 4
               Enter the elements one by one for Array B: 12 3 7 8 5
Sample output :  Median of array1 : 4
                 Median of array2 : 7
                 Median of both arrays : 5.5        

*/
#include <stdio.h>
int main ()
{
    //initialization
    int i, j, temp, n1, n2, mA1, mA2, mB1, mB2;				
    float medianA, medianB, finalmedian;

    //taking size of array A from the user
    printf("Enter the 'n' value for Array A: ");					
    scanf("%d", &n1);
    int arr1[n1];	
    
    
    //taking size of array B from the user
    printf("Enter the 'n' value for Array B: ");					
    scanf("%d", &n2);
    int arr2[n2];									

    //taking array A elements from the user
    printf("Enter the elements one by one for Array A: \n");				
    for( i = 1; i <= n1; i++ )
    {
	scanf("%d", &arr1[i]);
    }
    
    //taking array B elements from the user
    printf("Enter the elements one by one for Array B: \n");				
    for( i = 1; i <= n2; i++ )
    {
	scanf("%d", &arr2[i]);
    }

    //bubble sorting array A
    for ( i = 1; i <= n1 - 1; i++ )							
    {
	for ( j = 1; j <= n1 - i; j++ )
	{
	    if ( arr1[j] > arr1[j + 1] )
	    {
		temp = arr1[j];
		arr1[j] = arr1[j + 1];
		arr1[j + 1] = temp;
	    }
	}
    }

    //bubble sorting array B
    for ( i = 1; i <= n2 - 1; i++ )							
    {
	for ( j = 1; j <= n2 - i; j++ )
	{
	    if ( arr2[j] > arr2[j + 1] )
	    {
		temp = arr2[j];
		arr2[j] = arr2[j + 1];
		arr2[j + 1] = temp;
	    }
	}
    }

    //if length of array A is even
    if ( (n1 % 2) == 0 )									
    {
        //finding the middle element
	mA1 = arr2[(n1 / 2)];							
	mA2 = arr1[(n1 / 2) + 1];
	medianA = (float)(mA1 + mA2) / 2;					
	printf(" Median of array1 : %g\n", medianA);
    }
    
    //if length of array A is odd
    else										
    {
	medianA = arr1[( n1 / 2 ) + 1];						
	printf(" Median of array1 : %g\n", medianA);
    }

    //if length of array B is even
    if ( ( n2 % 2) == 0 )								
    {
        //finding the middle element
	mB1 = arr2[(n2 / 2)];							
	mB2 = arr2[(n2 / 2) + 1];
	medianB = (float)(mB1 + mB2) / 2;						
	printf("Median of array2 : %g\n", medianB);
    }
    else										
    {
	medianB = arr2[( n2 / 2 ) + 1];							
	printf("Median of array2 : %g\n", medianB);
    }

    //calculating median of both the arrays
    finalmedian = (medianA + medianB) / 2;						
    printf("Median of both arrays : %g\n", finalmedian);

    return 0;
}
