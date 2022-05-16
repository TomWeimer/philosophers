NAME =	philo

CC	 =	gcc -g -Wall -Wextra -Werror

SRCS =	srcs/main.c\
		srcs/process.c\
		srcs/threads_and_mutex.c\
		srcs/parsing/parsing.c\
		srcs/parsing/parsing_utils.c\
		srcs/routine/routine.c\
		srcs/routine/routine_utils.c\
		srcs/routine/time.c

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