/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vtoq.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 01:33:59 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/07 01:46:48 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** Euler angles to Quaternion
** Angles must be in radians.
*/

t_xyzw	vtoq(t_xyz euler)
{
	double c1;
    double s1;
    double c2;
    double s2;
    double c3;
    double s3;

	c1 = cos(euler.y * 0.5);
	s1 = sin(euler.y * 0.5);
	c2 = cos(euler.z * 0.5);
	s2 = sin(euler.z * 0.5);
	c3 = cos(euler.x * 0.5);
	s3 = sin(euler.x * 0.5);
	return ((t_xyzw){
		s1 * s2 * c3 + c1 * c2 * s3,
		s1 * c2 * c3 + c1 * s2 * s3,
		c1 * s2 * c3 - s1 * c2 * s3,
		c1 * c2 * c3 - s1 * s2 * s3
	});
}
