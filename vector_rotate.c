/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:34:32 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/06 18:38:06 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** Rotate point (vector p) by a given matrix.
*/

t_xyz	vector_rotate(t_xyz p, t_matrix mat)
{
	return ((t_xyz){
		mat.m[0][0] * p.x + mat.m[0][1] * p.y + mat.m[0][2] * p.z,
		mat.m[1][0] * p.x + mat.m[2][1] * p.y + mat.m[2][2] * p.z,
		mat.m[3][0] * p.x + mat.m[3][1] * p.y + mat.m[3][2] * p.z
	});
}
