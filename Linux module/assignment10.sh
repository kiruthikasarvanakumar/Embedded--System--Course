#!bin/bash/
<<doc
Name : S.kiruthika
Date : 09-02-2024
Description :Write a script to rename a file/directory replaced by lower/upper case letters
sample input :File.txt MyScript.SH MyFile007.txt dir/ Assign1/ newfolder/ 
sample output : Files are rename in lowercase and directories are renamed in upper case
                file.txt myfile007.txt myscript.sh DIR/ ASSIGN1/ NEWFOLDER/
doc
#run the loop based on the list of contents
for i in *; do

  #validating file or not
  if [ -f "$i" ]; then
  
          #check if it's file.txt
          if [ "$i" = "file.txt" ]; then
                opt="FILE.TXt!=file.txt"
          else
                #convert file name to lowercase
                opt=$(echo "$i" | tr '[:upper:]' '[:lower:]')
          fi
          
          #check the renaming
          if [ "$i" != "$opt" ]; then
          
              #rename the file
              mv "$i" "$opt"
          fi
   fi
   
   #chect if it's a directory
  if [ -d "$i" ]; then
  
          #convert the directory name to uppercase
          opt=$(echo "$i" | tr '[:lower:]' '[:upper:]')
           if [ "$i" != "$opt" ]; then
           
               #rename the directory
               mv "$i" "$opt"
           fi
  fi
done
   echo "Files are rename in lowercase and directories are renamed in upper case"
