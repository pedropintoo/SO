#!/bin/bash
# This script opens 4 terminal windows
i="0"
until [[ $i -ge 4 ]]; do
	gnome-terminal & i=$(($i+1))
done
