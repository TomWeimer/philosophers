/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:44:46 by tweimer           #+#    #+#             */
/*   Updated: 2022/03/05 13:51:40 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"
#include "../../includes/argument.h"

void	init_values(t_data *philosopher)
{
	int	i;

	i = 0;
	philosopher->end = 0;
	while (i <= 4)
	{
		philosopher->state[i] = 0;
		i++;
	}
	if (philosopher->args.max_meal != 0)
	{
		philosopher->end_type = END_EAT;
		philosopher->actual_meal = 0;
	}
	else
	{
		philosopher->end_type = END_DEATH;
		philosopher->actual_meal = -1;
	}
	pthread_mutex_init(&philosopher->death, NULL);
	philosopher->start = get_the_time();
	philosopher->last_meal = philosopher->start;
}

int	get_the_time(void)
{
	struct timeval	current_time;
	int				time;

	gettimeofday(&current_time, NULL);
	time = current_time.tv_sec * 1000;
	time += (current_time.tv_usec / 1000);
	return (time);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] != s2[i])
		return (0);
	return (1);
}

void	show_message(t_data *philosopher, char *message)
{
	int	time;

	if (philosopher->shared->stop_all == 0 || ft_strcmp(message, DEAD) == 1)
	{
		time = get_the_time();
		pthread_mutex_lock(&philosopher->shared->write);
		printf("%d		", time - philosopher->start);
		printf("%d	", philosopher->numero);
		printf("%s", message);
		pthread_mutex_unlock(&philosopher->shared->write);
	}
}

int	is_dead(t_data *philosopher)
{
	if (philosopher->end == 1)
	{
		if (philosopher->state[got_left_fork] == 1)
			pthread_mutex_unlock(philosopher->left_fork);
		if (philosopher->state[got_right_fork] == 1)
			pthread_mutex_unlock(philosopher->right_fork);
		return (1);
	}
	return (0);
}
