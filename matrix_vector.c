/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:33:53 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/06 16:39:35 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** Matrix to Euler-angles (vector) conversion.
** To avoid gimbal lock, check if pitch == +/-90
** To solve gimbal lock, yaw(z) = 0, calculate roll(u)
** Returns +/-PI radians for x/z and +/-PI_BY_TWO radians for y
*/

void	matrix_vector(t_matrix mat, t_xyz *out)
{
	out->y = -asin(mat.m[2][0]);
	if (mat.m[2][0] == 1)
	{
		out->z = 0;
		out->x = atan2(-mat.m[0][1], -mat.m[0][2]);
	}
	else if (mat.m[2][0] == -1)
	{
		out->z = 0;
		out->x = atan2(mat.m[0][1], mat.m[0][2]);
	}
	else
	{
		out->z = atan2(mat.m[1][0], mat.m[0][0]);
		out->x = atan2(mat.m[2][1], mat.m[2][2]);
	}
}
