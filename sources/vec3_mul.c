/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_mul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 01:48:33 by ngontjar          #+#    #+#             */
/*   Updated: 2020/09/10 02:11:13 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** Multiply, or "change length in the same direction."
*/

t_xyz	vec3_mul(t_xyz v, double scalar)
{
	return ((t_xyz){
		v.x * scalar,
		v.y * scalar,
		v.z * scalar
	});
}
