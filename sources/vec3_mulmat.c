/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_mulmat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:34:32 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/13 03:08:10 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** Rotate point (vector p) by a given matrix.
** TODO: Might actually need the 4th component.
*/

t_xyz	vec3_mulmat(t_xyz p, t_matrix mat)
{
	return ((t_xyz){
		p.x * mat.m[0][0] + p.y * mat.m[1][0] + p.z * mat.m[2][0],
		p.x * mat.m[0][1] + p.y * mat.m[1][1] + p.z * mat.m[2][1],
		p.x * mat.m[0][2] + p.y * mat.m[1][2] + p.z * mat.m[2][2]
	});
}
