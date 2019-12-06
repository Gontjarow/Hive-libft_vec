/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 19:41:11 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/06 16:33:23 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** r holds the rotation around X Y Z vector by W degrees.
** Tested with arbitrary axes and positive/negative degrees.
*/

void	matrix_rotation(t_xyzw r, t_matrix *out)
{
	t_xyz	v;
	double	d;

	v = (t_xyz){r.x * r.x, r.y * r.y, r.z * r.z};
	d = r.x * r.x + r.y * r.y + r.z * r.z;
	r.w *= DEG_TO_RAD;
	out->m[0][0] = (v.x + (v.y + v.z) * cos(r.w)) / d;
	out->m[0][1] = (r.x * r.y * (1 - cos(r.w)) - r.z * sqrt(d) * sin(r.w)) / d;
	out->m[0][2] = (r.x * r.z * (1 - cos(r.w)) + r.y * sqrt(d) * sin(r.w)) / d;
	out->m[0][3] = 0;
	;
	out->m[1][0] = (r.x * r.y * (1 - cos(r.w)) + r.z * sqrt(d) * sin(r.w)) / d;
	out->m[1][1] = (v.y + (v.x + v.z) * cos(r.w)) / d;
	out->m[1][2] = (r.y * r.z * (1 - cos(r.w)) - r.x * sqrt(d) * sin(r.w)) / d;
	out->m[1][3] = 0;
	;
	out->m[2][0] = (r.x * r.z * (1 - cos(r.w)) - r.y * sqrt(d) * sin(r.w)) / d;
	out->m[2][1] = (r.y * r.z * (1 - cos(r.w)) + r.x * sqrt(d) * sin(r.w)) / d;
	out->m[2][2] = (v.z + (v.x + v.y) * cos(r.w)) / d;
	out->m[2][3] = 0;
	;
	out->m[3][0] = 0;
	out->m[3][1] = 0;
	out->m[3][2] = 0;
	out->m[3][3] = 1;
}
