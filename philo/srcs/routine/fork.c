/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:44:40 by tweimer           #+#    #+#             */
/*   Updated: 2022/03/05 13:47:09 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"
#include "../../includes/argument.h"

void	ft_grab_a_fork(t_data *philosopher, int side)
{
	if (side == 1)
	{
		pthread_mutex_lock(philosopher->left_fork);
		philosopher->state[got_left_fork] = 1;
	}
	else
	{
		pthread_mutex_lock(philosopher->right_fork);
		philosopher->state[got_right_fork] = 1;
	}
	show_message(philosopher, FORK);
}

void	ft_fork(t_data *philosopher)
{
	if (is_dead(philosopher))
		return ;
	ft_grab_a_fork(philosopher, 1);
	if (philosopher->args.nb > 1)
		ft_grab_a_fork(philosopher, 2);
	else
		usleep(philosopher->args.time[to_die] * 1000);
}
