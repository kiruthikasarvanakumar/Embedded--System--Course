#!/bin/bash
<<doc
Name : S.kiruthika
Date : 06-02-2024
Description : Read and generate a pattern numbers increasing from top to bottom
Sample input : 4
Sample output:
1
2 3
4 5 6
7 8 9 10
doc
read -p "Enter one number": num #read one number from the user
count=0
for row in `seq $num ` #run the outer loop based on the num times(row)
do
        for col in  `seq $row ` #run the inner loop based on row times(col)
        do
           ((count++)) #increment the count variable
           echo -n "$count " #print the value without newline
        done
        echo "" #move to nextline after completing each row
done
