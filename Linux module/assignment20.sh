#!/bin/bash
Name : S.kiruthika
Date : 21-02-2024
Description : Write a script to replace 20% lines in a C file randomly and replace it with the pattern
Sample input :  Before replacing
               #incude <stdio.h>
               int main()
               {
                 printf(“Hello world\n”);
               }
            
Sample output: After replacing
               #incude <stdio.h>
               int main()
               {
                 <-----------Deleted------------>
               } 

doc

#check the commad line argument is passed or not
if [ $# -gt 0 ]
then
    
    #check the file is present or not
    if [ -f "$1" ]
    then
    
        #check the file contents
        if [ -s "$1" ]
        then
        
        #contents before replacing
        echo "Before replacing"
        cat "$1"
        
        #total lines in the file
        line=$(wc -l < "$1")
        if [ "$line" -gt 5 ]
        then
        
          #number of lines to be replaced
          div=$(($line / 5))
          for ((i = 0; i <= div; i++))
          do
            
            #use 'shuf' command to generate random numbers
            arr=`shuf -i 1-"$line" -n 1`
            sed -i "${arr}s/.*/<-------Deleted-------->/" "$1"
          done
          echo "After replacement"
          cat "$1"
       else
           echo "Not enough lines in the file to replace."
      fi
   else
      echo "Error : main2.c is empty file. So can’t replace the string."
   fi
  else
      echo "Error : No such a file."
  fi
else
   echo "Error : Please pass the file name through command line."
fi
