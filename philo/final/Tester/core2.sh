
#!/bin/bash
#Path from this directory to where your programm is
path_to_philo=".."
death_message="died"
eat_message="eating"
fork_message="has taken a fork"
think_message="thinking"
sleep_message="sleeping"
#Some colors
RESET="\033[0m"
RED="\033[0;31m"
GREEN="\033[0;32m"  
BLUE="\033[0;34m" 
WHITE_BOLD="\033[1;37m"

#Compilation
make -C $path_to_philo --quiet

## Test 5 ##
#tested during
timer=60
#output file
file="./logs/nobody_should_die/test5.log"
# command tested
cmd='../philo 4 410 200 200'
nohup script  $file  $cmd >/dev/null 2>&1 &
sleep $timer
if pgrep philo > /dev/null
then
	{
		RUN=1
		killall philo
	}
else
		RUN=0
fi
bash test5.sh $RUN $file $death_message $eat_message $sleep_message $fork_message $think_message