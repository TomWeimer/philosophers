/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:56:29 by tweimer           #+#    #+#             */
/*   Updated: 2022/03/05 13:56:44 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"
#include "../../includes/argument.h"

void	ft_death(t_data *philosopher)
{
	pthread_mutex_lock(&philosopher->shared->stop);
	if (philosopher->shared->stop_all == 0)
	{
		philosopher->shared->stop_all = 1;
		show_message(philosopher, DEAD);
	}
	pthread_mutex_unlock(&philosopher->shared->stop);
	philosopher->end = 1;
}

void	*time_to_die(void *s_data)
{
	t_data	*philosopher;
	int		current;

	philosopher = (t_data *)s_data;
	while (TRUE)
	{
		if (philosopher->shared->stop_all == 1)
		{
			philosopher->end = 1;
			break ;
		}
		pthread_mutex_lock(&philosopher->death);
		current = get_the_time();
		if (philosopher->end == 1)
			break ;
		if (current - philosopher->last_meal >= philosopher->args.time[to_die])
			break ;
		pthread_mutex_unlock(&philosopher->death);
		usleep(1);
	}
	if (philosopher->end == 0)
		ft_death(philosopher);
	return (NULL);
}

void	*routine(void *s_data)
{
	pthread_t	death;
	t_data		*philosopher;

	philosopher = (t_data *)s_data;
	init_values(philosopher);
	pthread_create(&death, NULL, time_to_die, philosopher);
	if (philosopher->args.nb > 1 && philosopher->numero % 2 == 0)
		usleep((philosopher->args.time[to_die] * 1000) / 10);
	while (philosopher->end == 0)
	{
		ft_fork(philosopher);
		ft_eat(philosopher);
		ft_sleep(philosopher);
		ft_think(philosopher);
	}
	pthread_join(death, NULL);
	return (NULL);
}
