#!/bin/bash

script_usage() {
  echo "Script prolongs files with chosen suffix untill chosen length by concatenation of necessary ammount of chosen_fle copies."
  echo "Usage: ./file_prolonger.sh [suffix] [length] [chosen_file.extention]"
  exit
}

check_arguments() {
  if [ $# -lt 1 ] || [ $# -gt 3 ]; then
    echo "Error! Number of input arguments is incorrect."
    echo "Input between [1, 3] arguments. (Use '?' to understand the script mechanism)"
    exit
  fi
}

concatenation() {
  suffix=$1
  length=$2
  chosen_file=$3

  for receiver in *.$suffix; do
      filesize=$(stat -c%s "$receiver")
      while [ $filesize -lt $length ]; do
        while IFS= read -r -n 1 char; do
          echo -n "$char" >> $receiver
          filesize=$(stat -c%s "$receiver")
          if [ $filesize -ge $length ]; then
            break
          fi
        done < $chosen_file
      done
    done
}

file_prolonger() {
  for var in "$@"; do
    case $var in
      '?')
        script_usage
        ;;
    esac
  done

  check_arguments "$@"
  
  concatenation "$@"
}

file_prolonger "$@"
