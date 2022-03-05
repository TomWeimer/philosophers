/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:59:57 by tweimer           #+#    #+#             */
/*   Updated: 2022/03/05 14:05:18 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

t_data	guess_my_philo(t_args args, pthread_mutex_t *forks, int numero)
{
	t_data	the_sophists;

	the_sophists.args = args;
	the_sophists.left_fork = &forks[numero];
	if (args.nb > 1)
	{
		if (numero != args.nb - 1)
			the_sophists.right_fork = &forks[numero + 1];
		else
			the_sophists.right_fork = &forks[0];
	}
	else
		the_sophists.right_fork = NULL;
	the_sophists.numero = numero;
	return (the_sophists);
}

t_data	*ft_get_philo(t_args args, pthread_mutex_t *forks, t_shared *shared)
{
	int		i;
	t_data	*the_sophists;

	i = 0;
	the_sophists = malloc(sizeof(t_data) * args.nb);
	if (the_sophists == NULL)
		return (NULL);
	while (i < args.nb)
	{
		the_sophists[i] = guess_my_philo(args, forks, i);
		the_sophists[i].shared = shared;
		i++;
	}
	return (the_sophists);
}

void	ft_process(t_args args, pthread_mutex_t *forks)
{
	t_data		*the_sophists;
	pthread_t	*philo_id;
	t_shared	shared;

	pthread_mutex_init(&shared.stop, NULL);
	pthread_mutex_init(&shared.write, NULL);
	shared.stop_all = 0;
	philo_id = malloc(sizeof(pthread_t) * args.nb);
	the_sophists = ft_get_philo(args, forks, &shared);
	if (the_sophists == NULL || philo_id == NULL)
		return ;
	ft_threads(the_sophists, args.nb, philo_id);
	pthread_mutex_destroy(&shared.write);
	pthread_mutex_destroy(&shared.stop);
}
