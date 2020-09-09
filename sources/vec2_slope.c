/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_slope.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 19:31:38 by ngontjar          #+#    #+#             */
/*   Updated: 2020/09/09 20:53:01 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_math.h"

/*
** rise / run
** To use a single vector: vec2_slope(VEC2(0,0), v);
*/

double	vec2_slope(t_xy p_a, t_xy p_b)
{
	return ((p_a.y - p_b.y) / (p_a.x - p_b.x));
}
