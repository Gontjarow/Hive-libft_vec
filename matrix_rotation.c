/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axang_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 19:41:11 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/06 19:11:15 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** r holds the rotation around X Y Z vector by W degrees.
** Tested with arbitrary axes and positive/negative degrees.
*/

t_matrix		matrix_rotation(double x, double y, double z, double deg)
{
	t_xyz		v;
	double		d;
	t_matrix	matrix;

	matrix = matrix_identity();
	v = (t_xyz){x * x, y * y, z * z};
	d = x * x + y * y + z * z;
	deg *= DEG_TO_RAD;
	;
	matrix.m[0][0] = (v.x + (v.y + v.z) * cos(deg)) / d;
	matrix.m[0][1] = (x * y * (1 - cos(deg)) - z * sqrt(d) * sin(deg)) / d;
	matrix.m[0][2] = (x * z * (1 - cos(deg)) + y * sqrt(d) * sin(deg)) / d;
	;
	matrix.m[1][0] = (x * y * (1 - cos(deg)) + z * sqrt(d) * sin(deg)) / d;
	matrix.m[1][1] = (v.y + (v.x + v.z) * cos(deg)) / d;
	matrix.m[1][2] = (y * z * (1 - cos(deg)) - x * sqrt(d) * sin(deg)) / d;
	;
	matrix.m[2][0] = (x * z * (1 - cos(deg)) - y * sqrt(d) * sin(deg)) / d;
	matrix.m[2][1] = (y * z * (1 - cos(deg)) + x * sqrt(d) * sin(deg)) / d;
	matrix.m[2][2] = (v.z + (v.x + v.y) * cos(deg)) / d;
	;
	matrix.m[3][3] = 1;
	return (matrix);
}
