/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_and_mutex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:01:16 by tweimer           #+#    #+#             */
/*   Updated: 2022/03/05 14:01:42 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	ft_threads(t_data *the_sophists, int nb, pthread_t *philosopher)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		pthread_create(&philosopher[i], NULL, routine, &the_sophists[i]);
		i++;
	}
	i = 0;
	while (i < nb)
	{
		pthread_join(philosopher[i], NULL);
		i++;
	}
}
