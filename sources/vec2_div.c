/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_div.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 09:10:05 by ngontjar          #+#    #+#             */
/*   Updated: 2020/09/11 09:35:18 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** Divide individual components.
*/

t_xy	vec2_div(t_xy v, double scalar)
{
	return ((t_xy){
		v.x / scalar,
		v.y / scalar
	});
}