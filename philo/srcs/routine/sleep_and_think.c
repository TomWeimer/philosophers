/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_and_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:44:58 by tweimer           #+#    #+#             */
/*   Updated: 2022/03/05 13:57:16 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"
#include "../../includes/argument.h"

void	ft_sleep(t_data *philosopher)
{
	if (is_dead(philosopher))
		return ;
	philosopher->state[sleeping] = 1;
	show_message(philosopher, SLEEP);
	usleep(philosopher->args.time[to_sleep] * 1000);
	philosopher->state[sleeping] = 0;
}

void	ft_think(t_data *philosopher)
{
	if (is_dead(philosopher))
		return ;
	philosopher->state[thinking] = 1;
	show_message(philosopher, THINK);
	philosopher->state[thinking] = 0;
}
