NAME =	philo

CC	 =	gcc -Wall -Wextra -Werror

SRCS =	srcs/main.c\
		srcs/process.c\
		srcs/threads_and_mutex.c\
		srcs/parsing/parsing.c\
		srcs/parsing/parsing_utils.c\
		srcs/routine/routine.c\
		srcs/routine/routine_utils.c\
		srcs/routine/fork.c\
		srcs/routine/eat.c\
		srcs/routine/sleep_and_think.c

OBJS = ${SRCS:.c=.o}

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(OBJS) -o $(NAME)
clean:
	rm -rf $(OBJS)
fclean:		clean
	rm -rf $(NAME)
re:	clean fclean all

.PHONY: re fclean clean all