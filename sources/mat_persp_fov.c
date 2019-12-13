/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_persp_fov.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:24:57 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/13 19:09:25 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** Creates a matrix for perspective projection from FOV.
** ar = aspect ratio
** nz & fz = clipping
** vfov = vertical field of view (degrees)
*/

t_matrix	mat_persp_fov(double ar, double nz, double fz, double vfov)
{
	double hfov;
	double clip;

	if (nz <= 0 || fz <= 0 || nz >= fz || (vfov <= 0 || vfov >= PI))
		return (mat_identity());
	vfov = 1 / tan(vfov * 0.5 * DEG_TO_RAD);
	hfov = ar * vfov;
	clip = fz / (nz - fz);
	return ((t_matrix){
		.m[0][0] = hfov, .m[0][1] = 0, .m[0][2] = 0, .m[0][3] = 0,
		.m[1][0] = 0, .m[1][1] = vfov, .m[1][2] = 0, .m[1][3] = 0,
		.m[2][0] = 0, .m[2][1] = 0, .m[2][2] = clip, .m[2][3] = -1,
		.m[3][0] = 0, .m[3][1] = 0, .m[3][2] = nz * clip, .m[3][3] = 0
	});
}
