/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 19:41:11 by ngontjar          #+#    #+#             */
/*   Updated: 2020/09/09 20:33:49 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** "Angle-around-vector to Matrix"
** r holds the rotation around X Y Z vector by W degrees.
** Tested with arbitrary axes and positive/negative degrees.
*/

t_matrix		atom(t_xyzw r)
{
	t_xyz		v;
	t_xy		ang;
	double		d;
	double		sqrt_d;
	t_matrix	mat;

	mat = mat_identity();
	v = (t_xyz){r.x * r.x, r.y * r.y, r.z * r.z};
	d = r.x * r.x + r.y * r.y + r.z * r.z;
	sqrt_d = sqrt(d);
	r.w *= DEG_TO_RAD;
	ang = (t_xy){cos(r.w), sin(r.w)};
	;
	mat.m[0][0] = (v.x + (v.y + v.z) * ang.x) / d;
	mat.m[0][1] = (r.x * r.y * (1 - ang.x) - r.z * sqrt_d * ang.y) / d;
	mat.m[0][2] = (r.x * r.z * (1 - ang.x) + r.y * sqrt_d * ang.y) / d;
	;
	mat.m[1][0] = (r.x * r.y * (1 - ang.x) + r.z * sqrt_d * ang.y) / d;
	mat.m[1][1] = (v.y + (v.x + v.z) * ang.x) / d;
	mat.m[1][2] = (r.y * r.z * (1 - ang.x) - r.x * sqrt_d * ang.y) / d;
	;
	mat.m[2][0] = (r.x * r.z * (1 - ang.x) - r.y * sqrt_d * ang.y) / d;
	mat.m[2][1] = (r.y * r.z * (1 - ang.x) + r.x * sqrt_d * ang.y) / d;
	mat.m[2][2] = (v.z + (v.x + v.y) * ang.x) / d;
	return (mat);
}
