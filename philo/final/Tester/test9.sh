
#!/bin/bash
RESET="\033[0m"
RED="\033[3;31m"
GREEN="\033[3;32m"
BLUE="\033[1;34m" 
WHITE_BOLD="\033[1;37m"
echo -en "$WHITE_BOLD TEST 9: "

echo -en " 🚫 "
if [ $1 -eq 1 ]
	then
	{
		echo -en "$BLUE[$RED ✗ $BLUE]$RESET\n"
	}
	elif [ $1 -eq 0 ]
	then
	{
		echo -en "$BLUE[$GREEN ✓ $BLUE]$RESET\n"
		
	}
fi

echo -en "$WHITE_BOLD 💻  ../philo  4 -500 200 200 $RESET\n\n"

