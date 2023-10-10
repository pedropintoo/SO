#!/bin/bash
# For all the files in a folder, show their properties

case $# in
	[1] )
		
		if [[ ! -d "$1" ]]; then
  		echo "ERROR: '$1' is not a valid directory!"
  		exit 1;
		fi
		for f in $1/*; do
			if [[ -f $f ]]; then
				filepath="${f%/*}"
      	filename="${f##*/}"
      	newfile="new_${filename}"
    		cp "$f" "$filepath/$newfile"
				rm "$f"
			fi
		done

		;;
	[2] )
		case $1 in
			[-][r])
				if [[ ! -d $2 ]]; then
    			echo "ERROR: '$2' is not a valid directory!"
    			exit 1;
    		fi
				for f in $2/*; do
					filename="${f##*/}"
					if [[ -f $f && ${filename:0:4} = "new_" ]]; then
						filepath="${f%/*}"
          	filename="${f##*/}"
          	newfile="${filename:4}"
          	cp "$f" "$filepath/$newfile"
          	rm "$f"
					else
						echo "$f not start with 'new_' or not a file"
					fi
    		done
				;;
			* )
				echo "$0 -r <directory>"
				;;
		esac
		;;
	* )
	echo "ERROR: $0 <directory> || $0 -r <directory>"
  exit 1
	;;
esac
