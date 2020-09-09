/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_cross.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 14:12:18 by ngontjar          #+#    #+#             */
/*   Updated: 2020/09/10 02:03:26 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** Vector3 Cross-Product
** Returns a vector that is perpendicular to both vectors.
** Returns ZERO_VECTOR3 from parallel (or zero-length) vectors.
** *
** The magnitude of the product equals the area of a parallelogram
**	defined by the two vectors.
** For unit vectors, the magnitude of the product:
**	is 1.0 if they are perpendicular,
**	is 0.0 if they are parallel.
**	is sine of angle between the two vectors.
*/

t_xyz	vec3_cross(t_xyz a, t_xyz b)
{
	return ((t_xyz){
		(a.y * b.z) - (a.z * b.y),
		(a.x * b.z) - (a.z * b.x),
		(a.x * b.y) - (a.y * b.x)
	});
}
