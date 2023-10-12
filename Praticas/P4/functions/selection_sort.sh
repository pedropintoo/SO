#!/bin/bash
function selection_sort()
{
  # Initialize an empty array
  numbers=()

  # Read the file line by line and add each number to the array
  {
    while read line; do
      numbers+=("$line")
    done
  } < "$1"

  for ((i = 0; i < ${#numbers[@]}; i++)) do

    # find min
    min=${numbers[i]}
    min_idx=i
    for ((j = i+1; j < ${#numbers[@]}; j++)); do
      if [[ min -gt "${numbers[$j]}" ]]
      then
        min="${numbers[$j]}"
        min_idx=$j
      fi
    done

    if [[ "$i" -ne "$min_idx" ]]
    then
      # swap
      numbers[min_idx]=${numbers[i]}
      numbers[i]=$min
    fi


  done

  # Print the array elements
  for number in "${numbers[@]}"; do
      echo "-> $number"
  done
}