#!/bin/bash
source ./functions/comp2.sh

if [[ $# -ne 2 ]] ; then
	echo "ERROR: $0 <num1> <num2>"
	exit 1;
fi

comp2 "$1" "$2"

case "$?" in
  0)
    echo "$1 equal to $2"
    ;;
  1)
    echo "$1 is bigger!"
    ;;
  2)
    echo "$2 is bigger!"
    ;;
  *)
    echo "ERROR!!!"
    ;;
esac
