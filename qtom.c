/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qtom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 00:26:10 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/07 03:10:10 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** Quaternion to Matrix
** c1/c2/c3 are only calculation constants,
** so that nothing is calculated twice.
*/

t_matrix	qtom(t_xyzw q)
{
	t_matrix matrix;
	t_xyz c1;
	t_xyz c2;
	t_xyz c3;

	c1 = (t_xyz){2 * q.y * q.y, 2 * q.z * q.z, 2 * q.x * q.y};
	c2 = (t_xyz){2 * q.z * q.w, 2 * q.x * q.z, 2 * q.y * q.w};
	c3 = (t_xyz){2 * q.x * q.x, 2 * q.y * q.z, 2 * q.x * q.w};
	matrix = matrix_identity();
	return ((t_matrix){
		matrix.m[0][0] = 1.0 - c1.x - c1.y,
		matrix.m[0][1] = c1.z - c2.x,
		matrix.m[0][2] = c2.y + c2.z,
    	matrix.m[1][0] = c1.z + c2.x,
		matrix.m[1][1] = 1.0 - c3.x - c1.y,
		matrix.m[1][2] = c3.y - c3.z,
    	matrix.m[2][0] = c2.y - c2.z,
		matrix.m[2][1] = c3.y + c3.z,
		matrix.m[2][2] = 1.0 - c3.x - c1.x
	});
}
