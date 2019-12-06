/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axang_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 19:41:11 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/07 00:20:40 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** r holds the rotation around X Y Z vector by W degrees.
** Tested with arbitrary axes and positive/negative degrees.
*/

t_matrix		atom(t_xyzw r)
{
	t_xyz		v;
	double		d;
	t_matrix	mat;

	mat = matrix_identity();
	v = (t_xyz){r.x * r.x, r.y * r.y, r.z * r.z};
	d = r.x * r.x + r.y * r.y + r.z * r.z;
	r.w *= DEG_TO_RAD;
	;
	mat.m[0][0] = (v.x + (v.y + v.z) * cos(r.w)) / d;
	mat.m[0][1] = (r.x * r.y * (1 - cos(r.w)) - r.z * sqrt(d) * sin(r.w)) / d;
	mat.m[0][2] = (r.x * r.z * (1 - cos(r.w)) + r.y * sqrt(d) * sin(r.w)) / d;
	;
	mat.m[1][0] = (r.x * r.y * (1 - cos(r.w)) + r.z * sqrt(d) * sin(r.w)) / d;
	mat.m[1][1] = (v.y + (v.x + v.z) * cos(r.w)) / d;
	mat.m[1][2] = (r.y * r.z * (1 - cos(r.w)) - r.x * sqrt(d) * sin(r.w)) / d;
	;
	mat.m[2][0] = (r.x * r.z * (1 - cos(r.w)) - r.y * sqrt(d) * sin(r.w)) / d;
	mat.m[2][1] = (r.y * r.z * (1 - cos(r.w)) + r.x * sqrt(d) * sin(r.w)) / d;
	mat.m[2][2] = (v.z + (v.x + v.y) * cos(r.w)) / d;
	return (mat);
}
