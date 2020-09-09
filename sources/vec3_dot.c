/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_dot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 14:03:29 by ngontjar          #+#    #+#             */
/*   Updated: 2020/09/10 02:10:33 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** Vector3 Dot-Product
** Returns the magnitude of the vector that would result
** from "projecting" one vector onto the other.
** (The correct result does not depend on their order.)
** *
** scalar == cosine of angle between the vectors
** Parallel when (scalar == 1)
** Orthogonal when (scalar == 0)
** Opposite when (scalar == -1)
*/

double	vec3_dot(t_xyz a, t_xyz b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}
