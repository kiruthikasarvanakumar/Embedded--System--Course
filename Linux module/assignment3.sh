#!/bin/bash
<<doc
Name : S.kiruthika
Date : 06-02-2024
Description : Write a script for arithmetic calculator using command line argument
Sample input : 25+41
Sample output: 66
doc
#check if command-line arguments are provided
if [ $# -gt 0 ]; then
        #check if exactly three arguments provided
    if [ $# -eq 3 ]; then
            #perform arithmetic operation based on the second argument(operator)
        case $2 in
             +) #addition
                add=$(expr  "$1 + $3" | bc)
                echo "$1 $2 $3 = $add"
                ;;
            -) #subtraction
                sub=$(expr "$1- $3" | bc)
                echo "$1 $2 $3 = $sub"
                ;;
            x) #multiplication
                mul=$(expr "$1 * $3" | bc)
                echo "$1 $2 $3 = $mul"
                ;;
            /) #division
                #calculate division with two decimal places using bc
                div=$(echo "scale=2; $1 / $3" | bc)
                echo "$1 $2 $3 = $div"
                ;;
            *) #default
                echo "Error : Invalid operator"
                ;;
        esac
    else
       echo "Error:Please pass 3 arguments."
       echo "Usage:./arithmatic calc.sh 2.3 + 6.7"
   fi
else
   echo  "Error : Please pass the arguments through command line."
   echo  "Usage:./arithmatic_calc.sh 2.3 + 6.7"
fi
