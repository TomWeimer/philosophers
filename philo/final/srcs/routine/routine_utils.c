/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:44:46 by tweimer           #+#    #+#             */
/*   Updated: 2022/03/14 20:18:03 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"
#include "../../includes/argument.h"

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

int	show_message(t_data *philosopher, char *message)
{
	static int	done = 1;
	int			time;

	if (philosopher->shared->stop_all == 1)
		return (0);
	pthread_mutex_lock(&philosopher->shared->write);
	if (done == 1)
	{
		time = get_the_time();
		printf("%d		", time - philosopher->start);
		printf("%d	", philosopher->numero);
		printf("%s", message);
		if (ft_strcmp(DEAD, message) == 1)
			done = 0;
	}
	pthread_mutex_unlock(&philosopher->shared->write);
	return (done);
}

void	*is_mort(t_data *philosopher)
{
	if (philosopher->state[got_left_fork] == 1)
		pthread_mutex_unlock(philosopher->left_fork);
	if (philosopher->state[got_right_fork] == 1)
		pthread_mutex_unlock(philosopher->right_fork);
	return (NULL);
}

void	ft_usleep(t_data *philosopher, int time_in_ms)
{
	int	start;

	start = 0;
	start = get_the_time();
	while (philosopher->is_dead == 0 && ((get_the_time() - start) < time_in_ms))
	{
		usleep(1);
	}
}
