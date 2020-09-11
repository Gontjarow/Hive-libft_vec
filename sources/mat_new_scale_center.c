/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_new_scale_center.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 18:50:39 by ngontjar          #+#    #+#             */
/*   Updated: 2020/09/11 05:04:49 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

t_matrix	mat_new_scale_center(double x, double y, double z, t_xyz center)
{
	return ((t_matrix){.m = {
		{x, 0, 0, 0},
		{0, y, 0, 0},
		{0, 0, z, 0},
		{
			center.x * (1 - x),
			center.y * (1 - y),
			center.z * (1 - z),
			1
		}
	}});
}
