/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_norm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 00:37:38 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/07 01:27:42 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

t_xyzw	quat_norm(t_xyzw q)
{
	double normalize;

	normalize = 1 / sqrt((q.x * q.x) + (q.y * q.y) + (q.z * q.z) + (q.w * q.w));
	return ((t_xyzw){
		q.x *= normalize,
		q.y *= normalize,
		q.z *= normalize,
		q.w *= normalize
	});
}
