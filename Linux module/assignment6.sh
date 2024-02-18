#!/bin/bash
<<doc
Name : S.kiruthika
Date : 07-02-2024
Description : Write a script to print the length of each and every string using arrays
Sample input : Length of string (hello)
Sample output: 5
doc
arr=("$@") #first store all the command line arguments input in one array
if [ $# -ne 0 ]; #check the command line argument is passed or not
then
        for i in "${arr[@]}"; #run the loops based on all the array elements
        do
           len=${#i} #find the length for all strings one by one
           echo "Length of string ($i) - $len" #print the length of each string inside the loop
        done
else
        echo "Error : Please pass the arguments through command-line."
fi
