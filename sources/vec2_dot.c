/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_dot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 19:57:35 by ngontjar          #+#    #+#             */
/*   Updated: 2020/09/09 21:13:17 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_math.h"

/*
** Vector2 Dot-Product
** Returns the magnitude of the vector that would result
** from "projecting" one vector onto the other.
** (The correct result does not depend on their order.)
** *
** scalar == cosine of angle between the vectors
** Parallel when (scalar == 1)
** Orthogonal when (scalar == 0)
** Opposite when (scalar == -1)
*/

double	vec2_dot(t_xy a, t_xy b)
{
	return ((a.x * b.x) + (a.y * b.y));
}
