#!/bin/bash
# select structure to create menus
user=$(who | cut -d " " -f1 -)
PS3="$user>"
select arg in $@; do
	if [[ $REPLY -lt 1 || $REPLY -gt $# ]]; then
		echo "You picked wrong!"
		exit 1;
	fi
	echo "You picked $arg ($REPLY)."
done
