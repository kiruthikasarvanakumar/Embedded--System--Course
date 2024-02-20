#!bin/bash/
<<doc
Name : S.kiruthika
Date : 08-02-2024
Description : Write script to print contents of file from given line number to next given number of lines.
sample input : line number 1
               line number 2
               line number 3
               line number 4
               line number 5
                  ./print_lines.sh 2 3 myfile.txt
sample output : line number 2
                line number 3
                line number 4
doc

#check the command line argument is passed or not
if [ $# -eq 3 ];
then
        #find the line count of the file
        line=$(wc -l < "$3")
        #add the sum of first two arguments
        sum=$(expr $1 + $2)
        sum1=$(expr $sum - 1)
        
        #check if the files has enough lines
        if [ $line -ge $sum1 ];
        then
           #start-line to end-line
           echo "$(head -n $sum1 $3 | tail -n $2)"
        else
           echo "Error: data.txt is having only 10 lines. file should have atleast 14 lines"
        fi
else
    echo "Error: arguments missing!"
    echo "Usage: ./file_filter.sh start_line upto_line filename"
    echo "For eg. ./file_filter.sh 5 5 <file>"
fi
