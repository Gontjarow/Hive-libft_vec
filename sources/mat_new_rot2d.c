/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_new_rot2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 03:05:49 by ngontjar          #+#    #+#             */
/*   Updated: 2020/09/11 08:35:54 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** https://en.wikipedia.org/wiki/Rotation_matrix#In_two_dimensions
** *
** Equivalent to:
** x = (x * cos) - (x * sin)
** y = (y * sin) + (y * cos)
*/

t_matrix	mat_new_rot2d(float radians)
{
	double c;
	double s;

	c = cos(radians);
	s = sin(radians);
	return ((t_matrix){.m = {
		{c, -s, 0, 0},
		{s, c, 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1}
	}});
}
