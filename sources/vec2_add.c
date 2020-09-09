/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 01:59:30 by ngontjar          #+#    #+#             */
/*   Updated: 2020/09/09 20:49:58 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** A + B
*/

t_xy	vec2_add(t_xy a, t_xy b)
{
	return ((t_xy){
		a.x + b.x,
		a.y + b.y,
	});
}
