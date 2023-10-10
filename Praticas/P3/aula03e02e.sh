#!/bin/bash
# Condition block if
if [[ "$1" -gt 5 ]] && [[ "$1" -lt 10 ]] ; then
	echo $1: "número maior do que 5 e menor do que 10"
else
	echo $1: "numero menor (ou igual) do que 5 ou maior (ou igual) do que 10"
fi
