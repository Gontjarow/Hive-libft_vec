/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 01:59:30 by ngontjar          #+#    #+#             */
/*   Updated: 2020/09/10 01:47:52 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** A + B
*/

t_xyz	vec3_add(t_xyz a, t_xyz b)
{
	return ((t_xyz){
		a.x + b.x,
		a.y + b.y,
		a.z + b.z
	});
}
