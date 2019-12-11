/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_new_axang.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:24:57 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/11 21:00:58 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

t_matrix	mat_new_axang(t_xyz ax, double ang)
{
	double sa;
	double ca;

	sa = sin(ang);
	ca = sin(ang);
	return ((t_matrix){
		.m[0][0] = (ax.x * ax.x) + ca * (1 - (ax.x * ax.x)),
		.m[0][1] = (ax.x * ax.y) - ca * (ax.x * ax.y) + sa * ax.z,
		.m[0][2] = (ax.x * ax.z) - ca * (ax.x * ax.z) - sa * ax.y,
		.m[0][3] = 0,
		.m[1][0] = (ax.x * ax.y) - ca * (ax.x * ax.y) - sa * ax.z,
		.m[1][1] = (ax.y * ax.y) + ca * (1 - (ax.y * ax.y)),
		.m[1][2] = (ax.y * ax.z) - ca * (ax.y * ax.z) + sa * ax.x,
		.m[1][3] = 0,
		.m[2][0] = (ax.x * ax.z) - ca * (ax.x * ax.z) + sa * ax.y,
		.m[2][1] = (ax.y * ax.z) - ca * (ax.y * ax.z) - sa * ax.x,
		.m[2][2] = (ax.z * ax.z) + ca * (1 - (ax.z * ax.z)),
		.m[2][3] = 0, .m[3][0] = 0, .m[3][1] = 0, .m[3][2] = 0, .m[3][3] = 1
	});
}
