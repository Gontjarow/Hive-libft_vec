/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_cross.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 19:54:12 by ngontjar          #+#    #+#             */
/*   Updated: 2020/09/09 21:16:14 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_math.h"

/*
** Vector2 Cross-Product
** Returns the magnitude of the vector that would result
** from a regular 3D cross product of the input vectors,
** taking their Z values implicitly as 0.
** (i.e. treating the 2D space as a plane in the 3D space)
** The 3D cross product will be perpendicular to that plane.
** *
** The scalar returned is the Z value of the 3D cross product vector.
** The sign of the scalar indicates a CW or CCW rotation.
** scalar == sine of angle between the vectors
** asin(scalar) == angle in radians
*/

double	vec2_cross(t_xy a, t_xy b)
{
	return ((a.x * b.y) - (a.y * b.x));
}
