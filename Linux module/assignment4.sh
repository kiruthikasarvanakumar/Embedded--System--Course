#!/bin/bash
<<doc
Name : S.kiruthika
Date : 07-02-2024
Description : Write a script to delete empty lines from a file
Sample input :  Hello


How
Sample output: Hello
How
doc
if [ $# -ge 1 ]; # check the command line argument is passed or no.
then
        file="$1" #assign the file name to the variable
        if [ -f "$file" ]; then #check if file exists or not
           sed -i '/^[[:blank:]]*$/d' "$file" # sed used to delete empty lines from the file
           echo "Empty lines are deleted"
           cat "$file" >delete.txt  # output after removing empty lines
           cat delete.txt #display the content of delete.txt
        else
           echo "Error: File '$file' not found."
       fi
else
        echo "Error: Please pass the file name through command line."
fi
