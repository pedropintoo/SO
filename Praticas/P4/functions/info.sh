# Data de hoje, nome do PC, nome do utilizador
function info()
{
  date
	echo "Computer: $HOSTNAME"
	echo "User: $USER"

  return 0;
}