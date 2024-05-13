/*
Name : S.Kiruthika
Date : 24-04-2024
Description : WAP to convert Little Endian data to Big Endian
Sample input : Enter the size: 2
               Enter any number in Hexadecimal: ABCD
Sample output : After conversion CDAB
*/
#include <stdio.h>
int main()
{
    // varible declaration
	int size, num; 

    // read size from user
	printf("Enter the size: ");
	scanf("%d", &size);

    // read hexadecimal value from user
	printf("Enter any number in Hexadecimal: ");
	scanf("%X", &num); 
    // ptr varible stroing addr of varible number
	char *ptr = (char *)&num; 

    // temporary varible
	char temp; 
    // short varible
	if ( size == 2 ) 
	{
		temp = *ptr;
		*ptr = *(ptr+1);
		*(ptr+1) = temp;
	}
    // swaping the values
	else if ( size == 4 ) 
	{
		char temp1;
		temp = *ptr;
		*ptr = *(ptr+3);
		*(ptr+3) = temp;        
		temp1 = *(ptr+1);
		*(ptr+1) = *(ptr+2);
		*(ptr+2) = temp1;
	}
	printf("After conversion %X\n", num); 
	return 0;
}
