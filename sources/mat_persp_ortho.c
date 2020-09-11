/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_persp_ortho.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:24:57 by ngontjar          #+#    #+#             */
/*   Updated: 2020/09/11 08:02:37 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** Creates a matrix for orthographic projection from nz dimensions.
** w & h = view width/height dimensions
** nz & fz = clipping
*/

t_matrix	mat_persp_ortho(double w, double h, double nz, double fz)
{
	double clip;

	if (nz <= 0 || fz <= 0 || nz >= fz)
		return (mat_identity());
	clip = nz - fz;
	return ((t_matrix){.m = {
		{(2 / w),       0,           0, 0},
		{0,       (2 / h),           0, 0},
		{0,             0,  (1 / clip), 0},
		{0,             0, (nz / clip), 1}
	}});
}

/*
** https://www.scratchapixel.com/lessons/3d-basic-rendering/
** perspective-and-orthographic-projection-matrix/
** orthographic-projection-matrix
** *
** Remap scene bounding box into canonical view volume.
** (Unit cube with radius 1. Min pos -1,-1,-1. Max pos 1,1,1.)
** *
**  v(ertical), |  h(eight), | d(epth)
**    bot,top   | left,right | near,far
*/

t_matrix mat_persp_ortho2(t_xy v, t_xy h, t_xy d)
{
	double vertical;
	double height;
	double depth;

	height = h.y - h.x;
	vertical = v.y - v.x;
	depth = d.y - d.x;
	return ((t_matrix){.m = {
		{2 / height,            0,          0, 0},
		{0,          2 / vertical,          0, 0},
		{0,                     0, -2 / depth, 0},
		{
			-(h.y + h.x) / height,
			-(v.x + v.y) / vertical,
			-(d.y + d.x) / depth,
			1
		}
	}});
}
