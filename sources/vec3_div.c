/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_div.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 01:48:33 by ngontjar          #+#    #+#             */
/*   Updated: 2020/09/10 01:49:45 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** Divide individual components.
*/

t_xyz	vec3_div(t_xyz v, double scalar)
{
	return ((t_xyz){
		v.x / scalar,
		v.y / scalar,
		v.z / scalar
	});
}
