#!/bin/bash
<<doc
Name : S.kiruthika
Date : 19-02-2024
Description : Write a script to sort a given number in ascending or descending order
Sample input : -a 5 4 6 2 3 8 9 7 1
               -d 5 4 6 2 -3 8 -9 7 1
Sample output:  Ascending order of array is 1 2 3 4 5 6 7 8 9
                Descending order of array is 9 8 6 5 4 3 2 1

doc

#store the command line arguments in one array
arr=("$@")

#find the length of all array elements
length=$((${#arr[@]} - 1))

#check the command line argument is passed or not
if [ $# -eq 0 ]
then
    
     echo "Error : Please pass the argument through command line."
     echo "Usage : ./sorting -a/-d 4 23 5 6 3"
     exit 1
fi
     
     #case statement for Ascending and descending
     case $1 in                                        
                   -a) #case statement for ascending order
                   
                       #Ascending given Array
                       for i in `seq 0 $(($length-1))`                           
                       do
                         for j in `seq 1 $(($length-$i-1))`
                         do
                           sum=$((j + 1))
                           
                           #if  array number greater than next number swap number
                           if [ "${arr[$j]}" -gt  "${arr[$sum]}" ]   
                           then
                                
                                #swap the elements
                                temp="${arr[$j]}"
                                arr[$j]="${arr[$sum]}"
                                arr[$sum]="$temp"
                            fi
                          done
                        done
                        #Display the given array in Ascending order
                        echo "Ascending order of array is ${arr[@]:1}"
                        ;;
                        
                    -d) #Case statement for descending order
                        for i in `seq 0 $(($length-1))`                             
                        do
                          for j in `seq 1 $(($length-$i-1))`
                          do
                            sum=$((j + 1))
                            
                            #Condition for the value less than next value
                            if [ "${arr[$j]}"  -lt  "${arr[$sum]}" ]    
                            then
                                 
                                 #If less than swap the values and store it in array
                                 temp="${arr[$j]}"                             
                                 arr[$j]="${arr[$sum]}"
                                 arr[$sum]="$temp"
                            fi
                          done
                        done
                           #Display ths descending order of array
                           echo "Descending order of array is ${arr[@]:1}"      

                           ;;                                                                                                                                                                                      
                  *) #default
                          
                          #if no option passed print the error message
                          echo "Error : Please pass the choice."
                          echo "Usage : ./sorting -a/-d 4 23 5 6 3"
                          ;;
      esac
