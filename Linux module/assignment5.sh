#!/bin/bash/
<<doc
Name : S.kiruthika
Date : 16-02-2024
Description : Write a script to perform arithmetic operation on digits of a given number
sample input :   bash assignment5.sh 1234+
sample output : Sum of digits = 10
doc

#to check the command line argument is passed or not
if [ $# -gt 0 ]
then

#store your input in one variable
var=$1

#get the value of the operator
opt=${var: -1}

#find the length and do (-2)
length=$((${#var}-2))
        
        #handle mu;tiple operations by using case statements
        case $opt in
                
                #addition
                +) add=${var:0:1}
                        for i in `seq 1 $length`
                        do
                          next=${var:$i:1}
                          add=$((add+next))
                        done
                           echo "sum of digits = $add"
                           ;;
                          
                #subtraction of digits 
                -) sub=${var:0:1}
                        for i in `seq 1 $length`
                        do
                                next=${var:$i:1}
                                sub=$((sub-next))
                        done
                            echo "Subtraction of digits = $sub"
                            ;;
                            
                #multiplication of digits
                x) mul=${var:0:1}
                         for i in `seq 1 $length`
                         do
                                 next=${var:$i:1}
                                 mul=$((mul*next))
                         done
                              echo "Multiplication of digits = $mul"
                              ;;
                              
                #division of digits
                /)div=${var:0:1}
                        for i in `seq 1 $length`
                        do
                                div=`echo "scale=2; $div/${var:$i:1}" | bc`
                        done
                             echo "Division of digits = $div"
                            ;;
                *)
                    
                    #if we dont pass any operator this error message will be printed
                    echo "Error: Operator missing or invalid operator, please pass operator as last digit (+,-,x,/)"
                    ;;
        esac

        else
            
            #If no argument passed this error message is printed
            echo "Error : Please pass the arguments through CL."
            echo "Usage : ./operator_dependent.sh 2345+"
        fi
