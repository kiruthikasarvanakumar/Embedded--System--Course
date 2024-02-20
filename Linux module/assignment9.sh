#!bin/bash/
<<doc
Name : S.kiruthika
Date : 11-02-2024
Description : Write a script to print system information using commands
Sample input : 1.currently logged user
               2.you shell directory
               3.home directory
                 Enter choice : 2
Sample output:  your shell is directory /bin/bash
doc
#initialize option to y
opt="y"

#loop to continue until the user stops opt to stop
while [[ $opt = "y" ]]; do 

        #display menu for system information
        echo "1. Currently logged users"
        echo "2.Your shell directory"
        echo "3.Home directory"
        echo "4.OS name & version"
        echo "5.Current working directory"
        echo "6.Number of users logged in"
        echo "7.Show all available shells in your system"
        echo "8.Hard disk information"
        echo "9.CPU information."
        echo "10.Memory Informations"
        echo "11.File system information."
        echo "12.Currently running process"
        
        #user to enter the choice
        read -p "Enter the choice:" choice 
        
        #gives output based on user choice
        case $choice in
                1)
                     echo "Currently logged users: `whoami`"
                     ;;
                2)
                     echo "Your shell directory: $SHELL"
                     ;;
                3)
                     echo "Home directory: ~"
                     ;;
                4)
                     echo  "OS name & version: `uname -r`"
                     ;;
                5)
                     echo "Current working directory: `pwd`"
                     ;;
                6)
                     echo "Number of users logged in:`who -q`"
                     ;;
                7)
                     echo "Show all available shells in your system:`cat/etc/shells`"
                     ;;
                8)
                     echo "Hard disk information: `hwinfo`"
                     ;;
                9)
                     echo "CPU information.: `cat /proc/cpuinfo`"
                     ;;
               10)
                    echo "Memory Informations: `cat /proc/meminfo`"
                    ;;
               11)
                    echo "File system information.: `df`"
                    ;;
               12)
                    echo  "Currently running process:.`ps`"
                    ;;
               *)
                    echo "Error : Invalid option, please enter valid option"
                     ;;
         esac
         
            #prompt user to continue or exit the loop
            read -p "Do you want to continue (y/n) ? " opt
done
