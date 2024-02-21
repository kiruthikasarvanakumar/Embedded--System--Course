#!/bin/bash
<<doc
Name : S.kiruthika
Date : 20-02-2024
Description : For each directory in the $PATH, display the number of executable files in that directory
Sample input :  Print directory and number of executable files one-by-one.
                Print the total number of executable files at last.
                Current dir: /usr/local/sbin
Sample output: current count: 0
doc

#!/bin/bash

#fetch all directories from the $path
arr=(`echo $PATH | tr ":" " " `)        

#initialize total =0
total=0                                   

#run the loops based on all the array elements
for i in ${arr[@]}                        
do
        #check for directory
        if [ -d $i ]                          
        then
        
           #initialize count=0
           count=0    
           
           #Print current directory name
           echo "Current dir:$i"    
           
           #Change the directory
           cd $i                            
           list=(`ls`)
           for i in ${list[@]}
           do   
           
             #get all file of that directory
             #check for file exist and is it executable
             if [ -f $i -a -x $i ]       
             then
                
                #Count the executable file
                count=$(($count+1))     
             fi
          done
          
          #print the count of current directory
          echo "Current Count:$count"      
          total=$(($total+$count))         
          fi
done
    echo "Total:$total"                    
