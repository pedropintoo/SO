#!/bin/bash
source ./functions/selection_sort.sh

if [[ "$#" -ne "1" ]]
then
  echo "$0 <file>"
  exit 1
fi;

# Files in ./numbers/*
selection_sort "$1"