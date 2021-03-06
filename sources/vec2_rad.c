/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_rad.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 20:42:17 by ngontjar          #+#    #+#             */
/*   Updated: 2020/09/09 21:19:32 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_math.h"

/*
** Vector2 to Radians
*/

double	vec2_rad(t_xy v)
{
	return (atan2(v.y, v.x));
}
