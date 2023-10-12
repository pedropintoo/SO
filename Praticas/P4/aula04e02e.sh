#!/bin/bash
source ./functions/comp2.sh

echo "Number 1:"
read n1

echo "Number 2:"
read n2


comp2 "$n1" "$n2"

case "$?" in
  0)
    echo "$n1 equal to $n2"
    ;;
  1)
    echo "$n1 are bigger!"
    ;;
  2)
    echo "$n2 are bigger!"
    ;;
  *)
    echo "ERROR!!!"
    ;;
esac
