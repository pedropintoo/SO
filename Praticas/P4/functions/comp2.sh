function comp2() 
{
	if [[ "$1" -eq "$2" ]]
	then
		return 0;
	else
		if [[ "$1" -gt "$2" ]]
		then
			return 1;
		else
			return 2;
		fi
	fi	
}
