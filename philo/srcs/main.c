/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:59:14 by tweimer           #+#    #+#             */
/*   Updated: 2022/03/05 13:59:52 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"
#include "../includes/argument.h"

pthread_mutex_t	*ft_create_forks(int nb)
{
	pthread_mutex_t	*forks;
	int				i;

	i = 0;
	forks = malloc (sizeof(pthread_mutex_t) * nb);
	while (i < nb)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	return (forks);
}

void	ft_free_and_destroy(pthread_mutex_t *forks, int nb_philo)
{
	int	i;

	i = 0;
	if (forks != NULL)
	{
		while (i < nb_philo)
		{
			pthread_mutex_destroy(&forks[i]);
			i++;
		}
		free(forks);
	}
}

void	ft_philosopher(int argc, char *argv[])
{
	t_args			args;
	pthread_mutex_t	*forks;

	forks = NULL;
	if (!get_args(&args, argc, argv))
		return ;
	forks = ft_create_forks(args.nb);
	if (forks == NULL)
	{
		ft_free_and_destroy(forks, args.nb);
		return ;
	}
	ft_process(args, forks);
	ft_free_and_destroy(forks, args.nb);
}

int	main(int argc, char *argv[])
{
	if (argc == 5 || argc == 6)
		ft_philosopher(argc, argv);
	else if (argc > 6)
		write(1, "Too many arguments\n", 19);
	else if (argc < 5)
		write(1, "Too few arguments\n", 18);
	return (1);
}
