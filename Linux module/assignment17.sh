#!bin/bash/
<<doc
Name : S.kiruthika
Date : 09-02-2024
Description : WAS to print contents of a directory without ls command
sample input : pwd is /home/user/ECEP/Linux_Systems/
sample output : Assignments Classwork

doc
#check the input cla is passed or not
if [ $# -gt 0 ]; then

        #create an array 'arr' and store all the inputs in one array
        arr=("$@")
        
        #run the loop based on all the array elements
        for i in "$@";do
        
           #check the given directory is present or not
           if [ -d "$i" ]; then
                cd "$i"
                
                #printing the current directory path
                echo  "/home/user: "
                echo "$(pwd)"
                
                #printing the header for directory contents
                echo "/home/user/ECEP:"
                
                #list the contents of the directory
                ls
           else
                #print an error message
                echo "output_ls.sh: Cannot access ‘Test’ : No such a file or directory."
           fi
        done
     else
         #if no arguments provided print the contents of current directory
         echo "/home/user:"
         echo "$(pwd)"
         echo "/home/user/ECEP:"
         ls
    fi
