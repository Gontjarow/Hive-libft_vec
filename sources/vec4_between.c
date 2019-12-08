/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_between.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 20:10:29 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/08 01:22:26 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

t_xyzw	vec4_between(t_xyz a, t_xyz b)
{
	t_xyzw	dot_calc;
	t_xyz	unit;
	double	w;
	double	m;

	if ((dot_calc.x = sqrt(vec3_dot(a, a) * vec3_dot(b, b))))
	{
		if ((dot_calc.y = vec3_dot(a, b) / dot_calc.x) > 0)
			return (ZERO_ROTATION);
		unit = vec3_div(vec3_cross(a, b), dot_calc.x);
		if ((dot_calc.z = vec3_dot(unit, unit)))
		{
			w = (dot_calc.y > -SIN45_DEG ? dot_calc.y + 1
				: dot_calc.z / (1 + sqrt(1 - dot_calc.z)));
			m = sqrt(dot_calc.z + (w * w));
			return (VEC4(unit.x / m, unit.y / m, unit.z / m, w / m));
		}
		else if ((m = sqrt(a.x * a.x + a.y * a.y)))
			return (VEC4(a.y / m, -a.x / m, 0, 0));
		return (VEC4(1, 0, 0, 0));
	}
	return (ZERO_ROTATION);
}
