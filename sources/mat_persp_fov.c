/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_persp_fov.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:24:57 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/11 21:29:58 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** Creates a matrix for perspective projection from FOV.
** ar = aspect ratio
** nearZ & farZ = clipping
** vfov = vertical field of view (radians)
*/

t_matrix	mat_persp_fov(double ar, double nearZ, double farZ, double vfov)
{
	double x;
	double y;
	double clip;

	if (nearZ <= 0 || farZ <= 0 || nearZ >= farZ || (vfov <= 0 || vfov >= PI))
		return (matrix_identity());
	y = 1 / tan(vfov * 0.5);
	x = y / ar;
	clip = farZ / (nearZ - farZ);
	return ((t_matrix){
		.m[0][0] = x, .m[0][1] = 0, .m[0][2] = 0, .m[0][3] = 0,
		.m[1][0] = 0, .m[1][1] = y, .m[1][2] = 0, .m[1][3] = 0,
		.m[2][0] = 0, .m[2][1] = 0, .m[2][2] = clip, .m[2][3] = -1,
		.m[3][0] = 0, .m[3][1] = 0, .m[3][2] = nearZ * clip, .m[3][3] = 0
	});
}
