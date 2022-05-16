#!/bin/bash
RESET="\033[0m"
RED="\033[3;31m"
GREEN="\033[3;32m"
BLUE="\033[1;34m" 
WHITE_BOLD="\033[1;37m"
echo -en "$WHITE_BOLD TEST 3: "

echo -en "\n$RESET	💀 "
if grep $3 $2 > /dev/null
	then
	{
		echo -en "$BLUE[$RED ✗ $BLUE]$RESET	"
		DIED=1
	}
	else
	{
		echo -en "$BLUE[$GREEN ✓ $BLUE]$RESET	"
		DIED=0
	}
fi

echo -en " 🚫 "
if [ $1 -eq 1 ]
	then
	{
		# if the program was running it's a failure 
		echo -en "$BLUE[$RED ✗ $BLUE]$RESET\n"
	}
	elif [ $1 -eq 0 ]
	then
	{
		echo -en "$BLUE[$GREEN ✓ $BLUE]$RESET\n"
		# else we check the result in $file
	}
fi

echo -en "$RESET 🍔 "
if [ $DIED -eq 1 ]
	then
		echo -en "$BLUE[$RED ✗ $BLUE] $RESET none\n"
else
{
	grep $4 $2 | wc -l | awk '{ if ($1 == 35 )  {printf "\033[3;32m ✓"; printf "\033[1;34m ] \033[0m"} else {printf "\033[3;31m ✗"; printf "\033[1;34m ] \033[0m"}} '
}
fi

echo -en "$WHITE_BOLD 💻  ../philo 5 800 200 200 7  $RESET\n\n"

