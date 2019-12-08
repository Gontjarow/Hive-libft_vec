/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_norm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 02:08:51 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/07 03:21:26 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** Optimal version of: return vector_div(v, vector_mag(v));
*/

t_xyz	vec3_norm(t_xyz v)
{
	double mag;

	mag = sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
	return ((t_xyz){
		v.x / mag,
		v.y / mag,
		v.z / mag
	});
}
