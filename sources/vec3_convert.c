/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <niko.gontjarow@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 14:40:26 by ngontjar          #+#    #+#             */
/*   Updated: 2020/09/16 18:09:59 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** Converts XYZ vectors to XY or XYZW with implicit values.
*/

t_xy	vec32(t_xyz v)
{
	return ((t_xy){v.x, v.y});
}

t_xyzw	vec34(t_xyz v)
{
	return ((t_xyzw){v.x, v.y, v.z, 1});
}
