#!/bin/bash
<<doc
Name : S.kiruthika
Date : 11-02-2024
Description : Write a script to print chess board
sample input : To print a black box: echo -e -n "\e[40m" " "
               To print a white box: echo -e -n "\e[47m" " "
               To make it normal: echo -e -n "\e[0m" " "
sample output : To print chess board

doc
# Function to print a black box

print_black_box() {
      echo -n "~[[47m """
}

# Function to print a white box
print_white_box() {
      echo -n "~[[40m """
}

reset_color() {
    echo -n "~[[0m """
}

# Loop to create the checkerboard pattern
 for ((row = 1; row <= 8; row++)); do
    for ((column = 1; column <= 8; column++)); do
        if (( (row + column) % 2 == 0 )); then
           print_black_box
        else
           print_white_box
        fi
    done
    reset_color
    echo # Move to the next row
  done
