/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <niko.gontjarow@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 14:42:29 by ngontjar          #+#    #+#             */
/*   Updated: 2020/09/16 18:10:32 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** Converts XYZW vectors to XY or XYZ by dropping the extra components.
*/

t_xy	vec42(t_xyzw v)
{
	return ((t_xy){v.x, v.y});
}

t_xyz	vec43(t_xyzw v)
{
	return ((t_xyz){v.x, v.y, v.z});
}
