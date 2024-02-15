#!/bin/bash
<<doc
Name : S.kiruthika
Date : 06-02-2024
Description : Read and generate a pattern numbers increment from left to right
Sample input : 4
Sample output:
1
12
123
1234
doc
read -p "Enter one number": num #read one number from the user
for row in `seq $num ` #run the outer loop based on our input times
do
        for col in  `seq $row ` #run the inner loop based on column times
        do
           echo -n "$col " #print the column values
        done
           echo
done
