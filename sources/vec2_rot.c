/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_rot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 20:41:22 by ngontjar          #+#    #+#             */
/*   Updated: 2020/09/11 20:55:10 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_math.h"

/*
** Rotate vector by angle (radians) and maintain length
*/

t_xy	vec2_rot(t_xy v, t_rad angle)
{
	return ((t_xy){
		v.x * cos(angle) - v.y * sin(angle),
		v.x * sin(angle) + v.y * cos(angle)
	});
}
