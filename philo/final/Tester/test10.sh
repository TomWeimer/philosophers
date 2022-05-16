
#!/bin/bash
RESET="\033[0m"
RED="\033[3;31m"
GREEN="\033[3;32m"
BLUE="\033[1;34m" 
WHITE_BOLD="\033[1;37m"
echo -en "$WHITE_BOLD TEST 10: "

echo -en "\n$RESET	💀 "
if grep $3 $2 > /dev/null
	then
	{
		echo -en "$BLUE[$GREEN ✓ $BLUE]$RESET	"
		DIED=1
	}
	else
	{
		echo -en "$BLUE[$RED ✗ $BLUE]$RESET	"
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

echo -en "$RESET	🧟 "
if grep -A10 $3 $2 | grep $4 > /dev/null
	then
		echo -en "$BLUE[$RED ✗ $BLUE]$RESET	"
elif grep -A10 $3 $2 | grep $5 > /dev/null
	then
		echo -en "$BLUE[$RED ✗ $BLUE]$RESET	"
elif grep -A10 $3 $2 | grep $6 > /dev/null
	then
		echo -en "$BLUE[$RED ✗ $BLUE]$RESET	"
elif grep -A10 $3 $2 | grep $7 > /dev/null
	then
		echo -en "$BLUE[$RED ✗ $BLUE]$RESET	"
else
	echo -en "$BLUE[$GREEN ✓ $BLUE]$RESET	"
fi

echo -en "$RESET ⏱️ "
if [ $DIED -eq 1 ]
	then
	{
		grep $3 $2 | awk '{ printf "\033[1;34m ["; if ($1 >= 500 && $1 <= 510 ) {printf "\033[3;32m ✓"; printf "\033[1;34m ] \033[0m" $1 "ms\n"} else {printf "\033[3;31m ✗"; printf "\033[1;34m ] \033[0m" $1 "ms expected 500 - 510 ms\n"}} '
	}
else
	echo -en "$BLUE[$RED ✗ $BLUE] $RESET none\n"
fi

echo -en "$WHITE_BOLD 💻  ../philo 4 500 200 2147483647  $RESET\n\n"

