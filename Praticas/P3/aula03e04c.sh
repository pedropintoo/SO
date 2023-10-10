#!/bin/bash
case $1 in
	[0-9][0-9] )
		Message="Arg1 -> Número entre [0-99]"
		;;
	* )	
		Message="Arg2 -> Número não validado"
		;;
esac
echo $Message

case $2 in
	[s][e][c]* )
		Message="Arg2 -> Palavra começa por 'sec'"
		;;
	* )
		Message="Arg2 -> Palavra não validada!"
		;;	
esac
echo $Message
