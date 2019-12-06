/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:34:26 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/06 16:36:50 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** Euler-angles (vector) to matrix rotation.
** Angles must be radians.
*/

void	vector_matrix(t_xyz vector, t_matrix *out)
{
	t_xy u;
	t_xy v;
	t_xy w;
	t_xy o;

	matrix_identity(out);
	u = (t_xy){sin(vector.x), cos(vector.x)};
	v = (t_xy){sin(vector.y), cos(vector.y)};
	w = (t_xy){sin(vector.z), cos(vector.z)};
	o = (t_xy){(u.x * v.x), (u.y * v.x)};
	;
	out->m[0][0] = (v.y * w.y);
	out->m[0][1] = (o.x * w.y) - (u.y * w.x);
	out->m[0][2] = (u.x * w.x) + (o.y * w.y);
	;
	out->m[1][0] = (v.y * w.x);
	out->m[1][1] = (u.y * w.y) + (o.x * w.x);
	out->m[1][2] = (o.y * w.x) - (u.x * w.y);
	;
	out->m[2][0] = (-v.x);
	out->m[2][1] = (u.x * v.y);
	out->m[2][2] = (u.y * v.y);
}
