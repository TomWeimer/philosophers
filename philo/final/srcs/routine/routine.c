/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:16:20 by tweimer           #+#    #+#             */
/*   Updated: 2022/03/14 20:27:03 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"
#include "../../includes/argument.h"

void	init_var(t_data *philosopher)
{
	int	i;

	i = 0;
	philosopher->is_dead = 0;
	philosopher->end_thread = 0;
	while (i <= 4)
	{
		philosopher->state[i] = 0;
		i++;
	}
	if (philosopher->args.max_meal != 0)
	{
		philosopher->end_type = END_EAT;
		philosopher->meal = 0;
	}
	else
	{
		philosopher->end_type = END_DEATH;
		philosopher->meal = -1;
	}
	pthread_mutex_init(&philosopher->time_eat, NULL);
	get_timeval(&philosopher->last_meal);
	philosopher->start = get_time(philosopher->last_meal);
}

int	ft_take_forks(t_data *philosopher)
{
	if (philosopher->is_dead == 1)
		return (0);
	pthread_mutex_lock(philosopher->left_fork);
	philosopher->state[got_left_fork] = 1;
	if (!show_message(philosopher, FORK))
		return (0);
	if (philosopher->args.nb <= 1)
	{
		usleep(philosopher->args.time[to_die] * 1000);
		return (0);
	}
	pthread_mutex_lock(philosopher->right_fork);
	philosopher->state[got_right_fork] = 1;
	if (!show_message(philosopher, FORK))
		return (0);
	return (1);
}

int	ft_eat(t_data *philosopher)
{
	if (philosopher->is_dead == 1)
		return (0);
	lock(philosopher->time_eat);
	get_timeval(&philosopher->last_meal);
	unlock(philosopher->time_eat);
	if (!show_message(philosopher, EAT))
		return (0);
	ft_usleep(philosopher, philosopher->args.time[to_eat]);
	if (philosopher->end_type == END_EAT)
	{
		philosopher->meal++;
		if (philosopher->meal == philosopher->args.max_meal)
		{
			philosopher->end_thread = 1;
			return (0);
		}
	}
	return (1);
}

int	ft_sleep(t_data *philosopher)
{
	if (philosopher->is_dead == 1)
		return (0);
	pthread_mutex_unlock(philosopher->left_fork);
	philosopher->state[got_left_fork] = 0;
	pthread_mutex_unlock(philosopher->right_fork);
	philosopher->state[got_right_fork] = 0;
	if (!show_message(philosopher, SLEEP))
		return (0);
	ft_usleep(philosopher, philosopher->args.time[to_sleep]);
	return (1);
}

void	*routine(void *s_data)
{
	t_data		*philosopher;
	pthread_t	mort;

	philosopher = (t_data *)s_data;
	init_var(philosopher);
	pthread_create(&mort, NULL, time_to_die, philosopher);
	pthread_detach(mort);
	if (philosopher->args.nb > 1 && philosopher->numero % 2 == 0)
		ft_usleep(philosopher, (philosopher->args.time[to_die]) / 20);
	while (philosopher->is_dead == 0)
	{
		if (!ft_take_forks(philosopher))
			break ;
		else if (!ft_eat(philosopher))
			break ;
		else if (!ft_sleep(philosopher))
			break ;
		else if (!show_message(philosopher, THINK))
			break ;
	}
	if (philosopher->is_dead == 0)
		philosopher->end_thread = 1;
	return (is_mort(philosopher));
}
