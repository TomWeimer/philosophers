#!/bin/bash
#Path from this directory to where your programm is
path_to_philo=".."
death_message="died"
eat_message="eating"
fork_message="has taken a fork"
think_message="thinking"
sleep_message="sleeping"

#Compilation
make -C $path_to_philo --quiet

#Some colors
RESET="\033[0m"
RED="\033[0;31m"
GREEN="\033[0;32m"  
BLUE="\033[0;34m" 
WHITE_BOLD="\033[1;37m"

## Test 1 ##
#tested during
timer=1
#output file
file="./logs/somebody_should_die/test1.log"
# command tested
cmd='../philo 1 200 200 200'
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
bash test1.sh $RUN $file $death_message $eat_message $sleep_message $fork_message $think_message
## Test 2 ##
#tested during
timer=60
#output file
file="./logs/nobody_should_die/test2.log"
# command tested
cmd='../philo  2 800 200 200'
#nohup script  $file  $cmd >/dev/null 2>&1 &
#sleep $timer
if pgrep philo > /dev/null
then
	{
		RUN=1
		killall philo
	}
else
		RUN=0
fi
bash test2.sh $RUN $file $death_message $eat_message $sleep_message $fork_message $think_message

## Test 3 ##
#tested during
timer=4
#output file
file="./logs/stop_after_eating/test3.log"
# command tested
cmd='../philo 5 800 200 200 7 '
#nohup script  $file  $cmd >/dev/null 2>&1 &
#sleep $timer
if pgrep philo > /dev/null
then
	{
		RUN=1
		killall philo
	}
else
		RUN=0
fi
bash test3.sh $RUN $file $death_message $eat_message $sleep_message $fork_message $think_message

## Test 4 ##
#tested during
timer=60
#output file
file="./logs/nobody_should_die/test4.log"
# command tested
cmd='../philo 5 800 200 200'
#nohup script  $file  $cmd >/dev/null 2>&1 &
#sleep $timer
if pgrep philo > /dev/null
then
	{
		RUN=1
		killall philo
	}
else
		RUN=0
fi
bash test4.sh $RUN $file $death_message $eat_message $sleep_message $fork_message $think_message

## Test 5 ##
#tested during
timer=60
#output file
file="./logs/nobody_should_die/test5.log"
# command tested
cmd='../philo 4 410 200 200'
#nohup script  $file  $cmd >/dev/null 2>&1 &
#sleep $timer
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



## Test 6 ##
#tested during
timer=4
#output file
file="./logs/somebody_should_die/test6.log"
# command tested
cmd='../philo 4 310 200 200 '
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
bash test6.sh $RUN $file $death_message $eat_message $sleep_message $fork_message $think_message

## Test 7 ##
#tested during
timer=1
#output file
file="./logs/invalid_arguments/test7.log"
# command tested
cmd='../philo 4 500 200 1.2 '
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
 bash test7.sh $RUN $file $death_message $eat_message $sleep_message $fork_message $think_message
## Test 8 ##
#tested during
timer=1
#output file
file="./logs/invalid_arguments/test8.log"
# command tested
cmd='../philo 4 0 200 200 '
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
bash test8.sh $RUN $file $death_message $eat_message $sleep_message $fork_message $think_message

## Test 9 ##
#tested during
timer=1
#output file
file="./logs/invalid_arguments/test9.log"
# command tested
cmd='../philo 4 -500 200 200'
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
bash test9.sh $RUN $file $death_message $eat_message $sleep_message $fork_message $think_message

## Test 10 ##
#tested during
timer=6
#output file
file="./logs/somebody_should_die/test10.log"
# command tested
cmd='../philo 4 500 200 2147483647 '
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
bash test10.sh $RUN $file $death_message $eat_message $sleep_message $fork_message $think_message

## Test 11 ##
#tested during
timer=60
#output file
file="./logs/nobody_should_die/test11.log"
# command tested
cmd='../philo 4 2147483647 200 200'
#nohup script  $file  $cmd >/dev/null 2>&1 &
#sleep $timer
if pgrep philo > /dev/null
then
	{
		RUN=1
		killall philo
	}
else
		RUN=0
fi
bash test11.sh $RUN $file $death_message $eat_message $sleep_message $fork_message $think_message

## Test 12 ##
#tested during
timer=3
#output file
file="./logs/invalid_arguments/test12.log"
# command tested
cmd='../philo 4 214748364732 200 200 '
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
bash test12.sh $RUN $file $death_message $eat_message $sleep_message $fork_message $think_message

## Test 13 ##
#tested during
timer=4
#output file
file="./logs/somebody_should_die/test13.log"
# command tested
cmd='../philo 4 200 210 200 '
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

bash test13.sh $RUN $file $death_message $eat_message $sleep_message $fork_message $think_message


make -C $path_to_philo fclean --quiet