#!/bin/bash/
<<doc
Name : S.kiruthika
Date : 16-02-2024
Description : Write a script to determine whether a given file system or mount point is mounted
sample input :  To Check that given file-system is mounted or not
                If its mounted, print free-space available in it.
                Other-wise print error message.
                bash assignment16.sh rootfs
sample output : File-system rootfs is mounted on / it is having 55% used space with 138448068 free
doc


if [ $# -ne 0 ]

then

#To get File
File=(`df | cut -d " " -f1`)

#To print use percentage
percentage=(`df | tr -s " " | cut -d " " -f4`)

 #To print Usedspace
Usedspace=(`df | tr -s " " | cut -d " " -f5`)

#To get where file system mounted
mount=(`df | tr -s " " | cut -d " " -f6`)

#initialize flag=1 to know file mounted or not
flag=1
  for i in `seq 1 $((${#File[@]}-1))`
        do

          #Check argument passed or not
          if [ $1  = ${File[$i]} ]
            then

                #Print Details of file system
                echo "File-system $1 is mounted on ${mount[$i]} it is having ${Usedspace[$i]} used space with ${percentage[$i]}KB free"
                flag=0
          fi
  done
          #if flag is equal to 1 print file is not mounted on system
          if [ $flag -eq 1 ]
          then
                echo "$1 is not Mounted"
          fi
else

   #print error message if no argument passed
   echo "Error : Please pass the name of the file-system through command line."
fi
