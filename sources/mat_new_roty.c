/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_new_roty.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 19:05:04 by ngontjar          #+#    #+#             */
/*   Updated: 2020/09/11 08:36:11 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** https://en.wikipedia.org/wiki/Rotation_matrix#In_three_dimensions
** *
** Todo: Double-check that signs for sine are correct.
** Note: These matrices might be diagonally flipped. (?)
** Note: This might be because of a difference in left/right-handedness. (?)
*/

t_matrix	mat_new_roty(float radians)
{
	double c;
	double s;

	c = cos(radians);
	s = sin(radians);
	return ((t_matrix){.m = {
		{c, 0, -s, 0},
		{0, 1, 0, 0},
		{s, 0, c, 0},
		{0, 0, 0, 1}
	}});
}
