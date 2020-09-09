/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_lerp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 20:38:30 by ngontjar          #+#    #+#             */
/*   Updated: 2020/09/09 20:58:56 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_math.h"

/*
** Linear-interpolation
** Returns a point between A towards B, based on T.
** When (T == 0), returns A
** When (T == 1), returns B
*/

t_xy	vec2_lerp(t_xy a, t_xy b, double t)
{
	return ((t_xy){
		a.x + ((b.x - a.x) * t),
		a.y + ((b.y - a.y) * t)
	});
}
