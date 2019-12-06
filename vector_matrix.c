/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:34:26 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/06 18:40:33 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** Euler-angles (vector) to matrix rotation.
** Angles must be radians.
*/

t_matrix	vector_matrix(t_xyz vector)
{
	t_xy		u;
	t_xy		v;
	t_xy		w;
	t_xy		p;
	t_matrix	matrix;

	matrix = matrix_identity();
	u = (t_xy){sin(vector.x), cos(vector.x)};
	v = (t_xy){sin(vector.y), cos(vector.y)};
	w = (t_xy){sin(vector.z), cos(vector.z)};
	p = (t_xy){(u.x * v.x), (u.y * v.x)};
	;
	matrix.m[0][0] = (v.y * w.y);
	matrix.m[0][1] = (p.x * w.y) - (u.y * w.x);
	matrix.m[0][2] = (u.x * w.x) + (p.y * w.y);
	;
	matrix.m[1][0] = (v.y * w.x);
	matrix.m[1][1] = (u.y * w.y) + (p.x * w.x);
	matrix.m[1][2] = (p.y * w.x) - (u.x * w.y);
	;
	matrix.m[2][0] = (-v.x);
	matrix.m[2][1] = (u.x * v.y);
	matrix.m[2][2] = (u.y * v.y);
	return (matrix);
}
