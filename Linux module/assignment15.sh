#!bin/bash/
<<doc
Name : S.kiruthika
Date : 10-02-2024
Description : Shell script to convert string lower to upper and upper to lower
Sample input :1 – Lower to upper
              2 – Upper to lower
              what is os?
Sample output:Please select option : 1
              WHAT IS OS?
              Please select option : 2
              what is os?
doc
#!/bin/bash

# Check the command line argument is passed or not
if [ $# -eq 0 ]; then
  echo "Error : Please pass the file name through command line."
  exit 1
fi
   
  filename="$1"
  
  #to check given file is present or not
  if [ ! -f "$filename" ]; then
          echo "Error: File not found"
          exit 1
  fi
  
     #check the given file has some contents or not
     if [ ! -s "$filename" ]; then
         echo "Error: No contents inside the file." 
         exit 1
     fi
             echo "Please select an option:"
             
             #to select the conversion type
             echo "1 – Lower to upper"
             echo "2 – Upper to lower"
             
             #read input from the user
             read -p "Option:" option
        case "$option" in
                1)
                    #convert contents lower to upper case
                    cat "$filename" | tr '[:lower:]' '[:upper:]'
                    ;;
                2)
                    #convert contents upper to lower case
                    cat "$filename" | tr '[:upper:]' '[:lower:]'
                    ;;
                *) #default
                     echo "Error: Invalid option."
                     exit 1
                     ;;

        esac
