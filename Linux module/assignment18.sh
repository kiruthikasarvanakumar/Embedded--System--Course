#!bin/bash/
<<doc
Name : S.kiruthika
Date : 14-02-2024
Description : Count the number of users with user IDs between given range.
Sample input : Fetch user-ids from the  /etc/passwd file.
               Count the no.of user-ids present in given range.
Sample output : Total count of user ID between 500 to 10000 is: 2

              
doc
#fetch the userid[f3] from etc/passwd and store it in a array
Array=($(cut -d ":" -f3 /etc/passwd))

#Initialize count=0
count=0 

#check the command line argument is passed or not
if [ $# -eq 0 ]  
then

  #For loop to get each userid
  for i in ${Array[@]}  
  do
  
    #By defualt if no CLA passed it should check how many userId are there
    if [ $i -gt 500 -a $i -lt 10000 ]  
    then
        count=$(($count+1))  #Increament the count
        fi
        done
        echo "Total count of user ID between 500 to 10000 is:$count" #Print the count
        
#Check the if CLA passed are equal 2
elif [ $# -eq 2 ]   
then

#condition to check first cla greater than Second
if [ $1 -lt $2 ]  
then
        for i in ${Array[@]}
        do
        #Check the number of id in between given range
        if [ $i -gt $1 -a $i -lt $2 ]  
        then
          #get the number how many present in between given range
          count=$(($count+1))
        fi
        done
        echo "Total count of user ID between $1 to $2 is:$count" #Print the count

 else
 
   #if first argument greater than second .print error message
   echo "Error:Invalid range .Please enter the valid range through CL." 
 fi
 else
 
   #if command line arguments are not equal to 0 and 2.print the error message
   echo "Error:Please pass 2 arguments throgh CL."  
   echo "Usage:./user_ids.sh 100 200"
 fi
