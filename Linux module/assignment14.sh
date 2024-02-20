#!/bin/bash/
<<doc
Name : S.kiruthika
Date : 17-02-2024
Description : Write script called say_hello, which will print greetings based on time
sample input : bash assignment14.sh 
sample output : Good noon kiruthika,have a nice day!
                This is Saturday 17 in February of 2024 (01 PM)
doc

#fetch the hour
hour=`date +%H| cut -d " " -f4 | cut -d ":" -f1`

#fetch the day 
day=`date +%A| cut -d " " -f1`

#fetch the date 
date=`date +%d| cut -d " " -f3`

#fetch the month
month=`date +%B| cut -d " " -f2`

#fetch the year
year=`date +%Y| cut -d " " -f6`

#fetch the time
time=`date +%I|  cut -d " " -f4`

#fetch the AM/PM
AMPM=`date +%p`

#if hour is between 5 and 12 print good morning
if [ $hour -ge 5 -a $hour -lt 12 ]
then
    Greet=`echo "Good morning"`
    
#if hour is between 12 and 14 print good noon
elif [ $hour -ge 12 -a $hour -lt 14 ]
then
    Greet=`echo "Good noon"`
    
#if hour is between 14 and 17 print good afternoon
elif [ $hour -ge 14 -a $hour -lt 17 ]
then
    Greet=`echo "Good afternoon"`
elif [ $hour -ge 17 -a $hour -lt 21 ]
then
    Greet=`echo "Good evening"`
else
    Greet=`echo "Good night"`
fi
#greeting message
echo  "$Greet $(whoami),have a nice day!"
echo "This is $day $date in $month of $year ($time $AMPM) "
