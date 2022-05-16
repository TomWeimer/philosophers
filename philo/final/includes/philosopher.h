/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:33:12 by tweimer           #+#    #+#             */
/*   Updated: 2022/03/14 20:38:27 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

# define SLEEP	"is sleeping\n"
# define EAT		"is eating\n"
# define THINK	"is thinking\n"
# define FORK	"has taken a fork\n"
# define DEAD	"died\n"
# define TRUE 1

# define END_EAT 1
# define END_DEATH -1

typedef struct s_args
{
	int	nb;
	int	max_meal;
	int	time[3];
}t_args;

typedef struct s_shared
{
	pthread_mutex_t	write;
	pthread_mutex_t	stop;
	int				stop_all;
	int				*report;
	int				end_program;
	int				nb;
}t_shared;

typedef struct s_data
{
	struct timeval	current_time;
	struct timeval	last_meal;
	int				numero;
	int				state[5];
	int				*la_fin;
	int				meal;
	int				start;
	int				is_dead;
	int				end_thread;
	int				end_type;
	t_args			args;
	t_shared		*shared;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	time_eat;
	pthread_mutex_t	mutex_start;
}t_data;

/*functions parsing*/
int		get_args(t_args *args, int argc, char *argv[]);
int		putnbr(char *str);
int		is_ok(char *str);
int		is_digits(char *str);
/*functions core of the programm*/
void	ft_process(t_args args, pthread_mutex_t *forks );
void	ft_threads(t_data *s_data, t_args args, pthread_t *philo, t_shared *p);
/*functions to manage the routine*/
void	*routine(void *s_data);
void	init_values(t_data *philosopher);
int		show_message(t_data *philosopher, char *message);
int		get_the_time(void);
void	*is_mort(t_data *philosopher);
int		ft_strcmp(char *s1, char *s2);
/*functions representing the state of the philosopher*/
int		ft_think(t_data *philosopher);
int		ft_sleep(t_data *philosopher);
int		ft_eat(t_data *philosopher);
int		ft_fork(t_data *philosopher);
void	ft_usleep(t_data *philosopher, int time_in_ms);
void	lock_and_change(pthread_mutex_t mutex, int *var, int num);
int		lock_and_check(pthread_mutex_t mutex, int *var, int num);
int		ft_drop_left_fork(t_data *philosopher);
int		ft_drop_right_fork(t_data *philosopher);
void	*time_to_die(void *s_data);
void	init_var(t_data *philosopher);
void	lock(pthread_mutex_t mutex);
void	unlock(pthread_mutex_t mutex);
void	get_timeval(struct timeval *current_time);
int		get_time(struct timeval current_time);
#endif