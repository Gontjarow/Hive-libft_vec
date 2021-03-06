/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_dist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 18:00:37 by ngontjar          #+#    #+#             */
/*   Updated: 2020/09/11 09:45:26 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** Distance between two points.
** Optimal version of: return vector_mag(vector_sub(a, b));
*/

double	vec3_dist(t_xyz a, t_xyz b)
{
	return (sqrt(
		(b.x - a.x) * (b.x - a.x) +
		(b.y - a.y) * (b.y - a.y) +
		(b.z - a.z) * (b.z - a.z)));
}
