/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:02:43 by tweimer           #+#    #+#             */
/*   Updated: 2022/03/05 14:03:00 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGUMENT_H
# define ARGUMENT_H
# define SIZE 3

typedef enum e_time
{
	to_die = 0,
	to_eat = 1,
	to_sleep = 2,
}t_enum;

typedef enum e_state
{
	is_eating = 0,
	sleeping = 1,
	thinking = 2,
	got_left_fork = 3,
	got_right_fork = 4
}t_enum_state;
#endif