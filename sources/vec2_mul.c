/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_mul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 20:40:05 by ngontjar          #+#    #+#             */
/*   Updated: 2020/09/09 21:18:03 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_math.h"

/*
** Multiply, or "change length in the same direction."
*/

t_xy	vec2_mul(t_xy v, double scalar)
{
	return ((t_xy){
		v.x * scalar,
		v.y * scalar
	});
}
