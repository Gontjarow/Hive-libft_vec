/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <niko.gontjarow@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 14:37:43 by ngontjar          #+#    #+#             */
/*   Updated: 2020/09/16 18:09:05 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** Converts XY vectors to XYZ or XYZW with implicit values.
*/

t_xyz	vec23(t_xy v)
{
	return ((t_xyz){v.x, v.y, 0});
}

t_xyzw	vec24(t_xy v)
{
	return ((t_xyzw){v.x, v.y, 0, 1});
}
