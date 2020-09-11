/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_norm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 00:37:38 by ngontjar          #+#    #+#             */
/*   Updated: 2020/09/11 10:47:35 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

t_rotation	rot_norm(t_rotation q)
{
	double mag;

	mag = 1 / sqrt((q.x * q.x) + (q.y * q.y) + (q.z * q.z) + (q.w * q.w));
	return ((t_xyzw){
		q.x *= mag,
		q.y *= mag,
		q.z *= mag,
		q.w *= mag
	});
}
