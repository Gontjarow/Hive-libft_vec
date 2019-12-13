/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vtoq.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 01:33:59 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/13 19:15:36 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** Euler angles to Quaternion
** Angles must be in radians.
*/

t_xyzw	vtoq(t_xyz euler)
{
	t_xyz	c;
	t_xyz	s;

	c.x = cos(euler.y * 0.5);
	s.x = sin(euler.y * 0.5);
	c.y = cos(euler.z * 0.5);
	s.y = sin(euler.z * 0.5);
	c.z = cos(euler.x * 0.5);
	s.z = sin(euler.x * 0.5);
	return ((t_xyzw){
		s.x * s.y * c.z + c.x * c.y * s.z,
		s.x * c.y * c.z + c.x * s.y * s.z,
		c.x * s.y * c.z - s.x * c.y * s.z,
		c.x * c.y * c.z - s.x * s.y * s.z
	});
}
