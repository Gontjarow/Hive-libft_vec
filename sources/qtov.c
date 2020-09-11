/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qtov.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 02:22:43 by ngontjar          #+#    #+#             */
/*   Updated: 2020/09/11 10:34:42 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** Quaternion to Euler angles (radians)
** Rotation q need not be normalized.
**  "The cutoff point for singulaties is set to 0.499 and -0.499
**  which corresponds to 86.3 degrees, this can be set closer to 90 if required
**  but we have to accept some inaccuracy around the singulaties."
**  - Euclideanspace.com
*/

t_xyz	qtov(t_rotation q)
{
	t_xyzw	sq;
	double	length;
	double	test;
	t_xy	c;

	sq = (t_xyzw){(q.x * q.x), (q.y * q.y), (q.z * q.z), (q.w * q.w)};
	length = sq.x + sq.y + sq.z + sq.w;
	test = q.x * q.y + q.z * q.w;
	c = (t_xy){2 * q.x, 2 * q.y};
	if (test > length * 0.499)
	{
		return ((t_xyz){0, 2 * atan2(q.x, q.w), PI_BY_TWO});
	}
	else if (test < length * -0.499)
	{
		return ((t_xyz){0, -2 * atan2(q.x, q.w), -PI_BY_TWO});
	}
	return ((t_xyz){
		atan2(c.x * q.w - c.y * q.z, -sq.x + sq.y - sq.z + sq.w),
		atan2(c.y * q.w - c.x * q.z, sq.x - sq.y - sq.z + sq.w),
		asin(2 * test / length)
	});
}
