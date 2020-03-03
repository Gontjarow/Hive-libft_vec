/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_rot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 19:46:59 by ngontjar          #+#    #+#             */
/*   Updated: 2020/03/03 19:49:53 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** This is literally terrible, but I needed this available fast.
** TODO: Write this out explicitly.
*/

t_xyz	vec3_rot(t_xyz v1, t_xyz v2)
{
	return (vec3_mulmat(v1, qtom(vtoq(v2))));
}
