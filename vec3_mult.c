/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_mult.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 01:48:33 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/07 03:21:27 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

t_xyz	vec3_mult(t_xyz v, double scalar)
{
	return ((t_xyz){
		v.x * scalar,
		v.y * scalar,
		v.z * scalar
	});
}
