/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:44:33 by tweimer           #+#    #+#             */
/*   Updated: 2022/03/05 13:46:23 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"
#include "../../includes/argument.h"

void	ft_drop_the_forks(t_data *philosopher)
{
	pthread_mutex_unlock(philosopher->left_fork);
	philosopher->state[got_left_fork] = 0;
	pthread_mutex_unlock(philosopher->right_fork);
	philosopher->state[got_right_fork] = 0;
}

void	ft_it_is_a_good_steak(t_data *philosopher)
{
	philosopher->state[is_eating] = 1;
	pthread_mutex_lock(&philosopher->death);
	show_message(philosopher, EAT);
	philosopher->last_meal = get_the_time();
	usleep(philosopher->args.time[to_eat] * 1000);
	pthread_mutex_unlock(&philosopher->death);
	philosopher->state[is_eating] = 0;
}

void	ft_eat(t_data *philosopher)
{
	if (is_dead(philosopher))
		return ;
	ft_it_is_a_good_steak(philosopher);
	ft_drop_the_forks(philosopher);
	if (philosopher->end_type == END_EAT)
	{
		philosopher->actual_meal++;
		if (philosopher->actual_meal == philosopher->args.max_meal)
			philosopher->end = 1;
	}
}
