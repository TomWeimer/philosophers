/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:38:19 by tweimer           #+#    #+#             */
/*   Updated: 2022/03/05 13:40:38 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"
#include "../../includes/argument.h"

int	is_digits(char *str)
{
	int	i;
	int	nb;

	nb = 0;
	i = 0;
	while (str[i])
	{
		if (nb == 0 && (str[i] >= '0' && str[i] <= '9'))
			nb = 1;
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == ' '))
			return (0);
		i++;
	}
	if (nb == 0)
		return (0);
	return (1);
}

int	is_ok(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	putnbr(char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb += str[i] - '0';
		i++;
	}
	return (nb);
}
