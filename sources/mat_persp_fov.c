/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_persp_fov.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:24:57 by ngontjar          #+#    #+#             */
/*   Updated: 2020/09/11 10:07:14 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** Creates a matrix for perspective projection from FOV.
** ar = aspect ratio
** nz & fz = clipping
** vfov = vertical field of view (degrees)
*/

t_matrix	mat_persp_fov(double ar, double nz, double fz, t_deg vfov)
{
	double hfov;
	double clip;

	if (nz <= 0 || fz <= 0 || nz >= fz || (vfov <= 0 || vfov >= PI))
		return (mat_identity());
	vfov = 1 / tan(vfov * 0.5 * DEG_TO_RAD);
	hfov = ar * vfov;
	clip = fz / (nz - fz);
	return ((t_matrix){.m = {
		{hfov, 0, 0, 0},
		{0, vfov, 0, 0},
		{0, 0, clip, -1},
		{0, 0, (nz * clip), 0},
	}});
}

/*
** https://www.scratchapixel.com/lessons/3d-basic-rendering/
** perspective-and-orthographic-projection-matrix/
** building-basic-perspective-projection-matrix
** *
** fov = degrees (horizontal)
** near & far = clipping planes
*/

t_matrix	mat_persp_fov2(t_deg fov, double near, double far)
{
	double scale;
	double dist;

	fov = fov * 0.5 * DEG_TO_RAD;
	scale = 1 / tan(fov);
	dist = far - near;
	return ((t_matrix){.m = {
		{scale, 0, 0, 0},
		{0, scale, 0, 0},
		{0, 0, -far / dist, -1},
		{0, 0, -far * near / dist, 0}
	}});
}
