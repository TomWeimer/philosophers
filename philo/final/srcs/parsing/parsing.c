/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:40:58 by tweimer           #+#    #+#             */
/*   Updated: 2022/03/05 14:03:41 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"
#include "../../includes/argument.h"

int	check_str(char *str)
{
	if (str == NULL || str[0] == '\0')
		return (0);
	if (!is_digits(str) || !is_ok(str))
		return (0);
	return (1);
}

int	check_args(t_args *args, int argc)
{
	int	index;

	index = 0;
	while (index < SIZE)
	{
		if (args->time[index] < 0 || args->time[index] > INT32_MAX)
		{
			write(1, "Error: arguments values\n", 24);
			return (0);
		}
		index++;
	}
	if (args->nb <= 0 || args->time[to_die] == 0
		|| (argc == 6 && args->max_meal <= 0))
	{
		write(1, "Error: arguments values\n", 24);
		return (0);
	}
	return (1);
}

int	get_values(char *str)
{
	if (!check_str(str))
		return (-1);
	return (putnbr(str));
}

int	get_args(t_args *args, int argc, char *argv[])
{
	int	index;

	index = 0;
	args->nb = get_values(argv[1]);
	args->max_meal = 0;
	while (index < SIZE)
	{
		args->time[index] = get_values(argv[index + 2]);
		index++;
	}
	if (argc == 6)
		args->max_meal = get_values(argv[5]);
	return (check_args(args, argc));
}
