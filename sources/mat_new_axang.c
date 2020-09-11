/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_new_axang.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:24:57 by ngontjar          #+#    #+#             */
/*   Updated: 2020/09/11 05:02:55 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** Matrix from Angle-around-Axis
** Note: W column (Wx Wy Wz) should initialize to 0.
*/

t_matrix	mat_new_axang(t_xyz ax, double ang)
{
	double s;
	double c;

	s = sin(ang);
	c = cos(ang);
	return ((t_matrix){.m = {
		{
			(ax.x * ax.x) + c * (1 - (ax.x * ax.x)),
			(ax.x * ax.y) - c * (ax.x * ax.y) + s * ax.z,
			(ax.x * ax.z) - c * (ax.x * ax.z) - s * ax.y
		},
		{
			(ax.x * ax.y) - c * (ax.x * ax.y) - s * ax.z,
			(ax.y * ax.y) + c * (1 - (ax.y * ax.y)),
			(ax.y * ax.z) - c * (ax.y * ax.z) + s * ax.x
		},
		{
			(ax.x * ax.z) - c * (ax.x * ax.z) + s * ax.y,
			(ax.y * ax.z) - c * (ax.y * ax.z) - s * ax.x,
			(ax.z * ax.z) + c * (1 - (ax.z * ax.z))
		},
		{0, 0, 0, 1}
	}});
}
