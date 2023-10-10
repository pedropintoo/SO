#!/bin/bash
# For all the files in a folder, show their properties
if [[ $# -ne 1 ]]; then
	echo "ERROR: $0 <directory>"
	exit 1
fi
if [[ ! -d "$1" ]]; then
	echo "ERROR: '$1' is not a valid directory!"
  exit 1;
fi

for f in $1/*; do
	file "$f"
done
