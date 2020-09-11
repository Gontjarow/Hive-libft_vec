/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_mag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 10:27:26 by ngontjar          #+#    #+#             */
/*   Updated: 2020/09/11 10:28:50 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** Magnitude, or length
*/

double	rot_mag(t_rotation q)
{
	return (sqrt((q.x * q.x) + (q.y * q.y) + (q.z * q.z) + (q.w * q.w)));
}
