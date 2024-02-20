#!bin/bash/
<<doc
Name : S.kiruthika
Date : 08-02-2024
Description : Display the longest and shortest user-names on the system
sample input : The Longest Name is: 
               The Shortest Name is
sample output :systemd-timesync
               lp
doc

#fetch the field number1 from the etc/passwd
#store it in one array
arr=($(cut -d ":" -f1 /etc/passwd))

#initialize variables for small and large usernames
small=${arr[0]}
large=${arr[0]}

#to get the length of the array
length=$((${#arr[@]} - 1))

#loop for rfinding smallest and largest usernames
for i in $(seq 0 $length);
do
  if [ ${#arr[$i]} -gt ${#large} ]; 
    then
          large=${arr[$i]}
  fi
  if [ ${#arr[$i]} -lt ${#small} ]; 
    then
          small=${arr[$i]}
  fi
done

   #printing the smallest and largest usernames
   echo "The Longest Name is:$large "
   echo "The Shortest Name is $small "
