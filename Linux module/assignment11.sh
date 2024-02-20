#!bin/bash/
<<doc
Name : S.kiruthika
Date : 10-02-2024
Description : Given album name and corresponding directory, this scripts renames the 
              jpg files with new name passed through command line
sample input : DSN001.jpg DSN002.jpg DSN003.jpg DSN004.jpg DSN005.jpg
sample output : All .jpg files in current directory is renamed as
                day_out001.jpg day_out002.jpg day_out003.jpg day_out005.jpg day_out004.jpg

doc

#check the command line argument is passed or not
if [ $# -gt 0 ]; then
          renamed_files=""
          
          #run the loop based on all the jpg files
          for i in *.jpg;
          do
          
          #extract digits from the file name
          digit=$(echo "$i" | tr -cd [:digit:])
          
          #check any digits were found
          if [ -n "$digit" ]; then
          
            #create a new file name with the .jpg and extract the digits
               opt="$1$digit.jpg"
               
               #rename the file
               mv "$i" "$opt"
               
          #to rename file to string
          if [ -z "$renamed_files" ]; then
                renamed_files="$opt"
            else
                renamed_files="$renamed_files $opt"
            fi
  else
          echo "$i: No digits found in the filename."
  fi
done
     #print the renamed file name
     echo "All .jpg files in current directory is renamed as"
     echo "$renamed_files"
  else
     # if no arguments passed print the error message
     echo "Error : Please pass the prefix name through command line."
  fi
