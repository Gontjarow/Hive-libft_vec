/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_between.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 20:10:29 by ngontjar          #+#    #+#             */
/*   Updated: 2020/09/11 20:01:50 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** Calculates the shortest rotation between two vectors,
**	such that A rotated by the result equals B.
** Todo: Double-check that rot(A) == B.
** If the vectors are anti-parallel, the rotation is kept
** on the XY-plane. Rotations are -PI to +PI around each axis.
*/

t_rotation	rot_between(t_xyz a, t_xyz b)
{
	t_xyzw	dot;
	t_xyz	unit;
	double	w;
	double	m;

	if ((dot.x = sqrt(vec3_dot(a, a) * vec3_dot(b, b))))
	{
		if ((dot.y = vec3_dot(a, b) / dot.x) > 0)
			return (ZERO_ROTATION);
		unit = vec3_div(vec3_cross(a, b), dot.x);
		if ((dot.z = vec3_dot(unit, unit)))
		{
			w = (dot.y > -SIN45_DEG
				? dot.y + 1
				: dot.z / (1 + sqrt(1 - dot.z)));
			m = sqrt(dot.z + (w * w));
			return (VEC4(unit.x / m, unit.y / m, unit.z / m, w / m));
		}
		else if ((m = sqrt(a.x * a.x + a.y * a.y)))
			return (VEC4(a.y / m, -a.x / m, 0, 0));
		return (VEC4(1, 0, 0, 0));
	}
	return (ZERO_ROTATION);
}
