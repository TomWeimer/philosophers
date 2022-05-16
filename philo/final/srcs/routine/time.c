/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:20:10 by tweimer           #+#    #+#             */
/*   Updated: 2022/03/14 20:24:33 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"
#include "../../includes/argument.h"

void	get_timeval(struct timeval *current_time)
{
	gettimeofday(current_time, NULL);
}

int	join_timeval(t_data *philo)
{
	int	time;

	time = (philo->current_time.tv_sec - philo->last_meal.tv_sec) * 1000;
	time += (philo->current_time.tv_usec - philo->last_meal.tv_usec) / 1000;
	return (time >= philo->args.time[to_die]);
}

int	get_time(struct timeval current_time)
{
	int	time;

	time = current_time.tv_sec * 1000;
	time += (current_time.tv_usec / 1000);
	return (time -1);
}

void	*time_to_die(void *s_data)
{
	t_data	*philo;

	philo = (t_data *)s_data;
	while (philo->end_thread == 0)
	{
		lock(philo->time_eat);
		get_timeval(&philo->current_time);
		if (join_timeval(philo))
			break ;
		unlock (philo->time_eat);
		usleep(1);
	}
	if (philo->end_type == END_DEATH || philo->meal != philo->args.max_meal)
		show_message(philo, DEAD);
	unlock (philo->time_eat);
	philo->is_dead = 1;
	if (*philo->shared->report == 0)
			*philo->shared->report = 1;
	return (NULL);
}
