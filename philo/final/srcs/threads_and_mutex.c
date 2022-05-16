/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_and_mutex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:01:16 by tweimer           #+#    #+#             */
/*   Updated: 2022/03/14 20:14:39 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	lock_and_check(pthread_mutex_t mutex, int *var, int num)
{
	int	rtn;

	rtn = 0;
	pthread_mutex_lock(&mutex);
	if (*var == num)
		rtn = 1;
	pthread_mutex_unlock(&mutex);
	return (rtn);
}

void	lock(pthread_mutex_t mutex)
{
	pthread_mutex_lock(&mutex);
}

void	unlock(pthread_mutex_t mutex)
{
	pthread_mutex_unlock(&mutex);
}

void	lock_and_change(pthread_mutex_t mutex, int *var, int num)
{
	pthread_mutex_lock(&mutex);
	*var = num;
	pthread_mutex_unlock(&mutex);
}

void	ft_threads(t_data *s_data, t_args args, pthread_t *philo, t_shared *p)
{
	int	i;

	i = 0;
	while (i < args.nb)
	{
		pthread_create(&philo[i], NULL, routine, &s_data[i]);
		i++;
	}
	while (1)
	{
		if (args.max_meal != 0)
			break ;
		if (*p->report == 1)
		{
			p->stop_all = 1;
			break ;
		}
	}
	i = 0;
	while (i < args.nb)
	{
		pthread_join(philo[i], NULL);
		i++;
	}
}
