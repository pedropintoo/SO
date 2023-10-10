#!/bin/bash
# This script checks the existence of a file
if [[ $# -ne 1 ]] ; then
	echo "ERROR: $0 <ficheiro>"
	exit 1;
fi

echo "Checking..."
if [[ -d $1 ]] ; then
	echo "$1 existe e é uma diretoria."
elif [[ -f $1 ]] ; then
	echo "$1 existe e é um ficheiro com permissões: $(ls -l $1 | cut -c 1-10)"
else
	echo "$1 não existe."
fi
echo "...done."
