/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_persp_wh.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:24:57 by ngontjar          #+#    #+#             */
/*   Updated: 2020/09/11 05:10:18 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** Creates a matrix for perspective projection from nz dimensions.
** w & h = view width/height dimensions
** nz & fz = clipping
*/

t_matrix	mat_persp_wh(double w, double h, double nz, double fz)
{
	double near2;
	double clip;

	if (nz <= 0 || fz <= 0 || nz >= fz)
		return (mat_identity());
	near2 = nz * 2;
	clip = fz / (nz - fz);
	return ((t_matrix){.m = {
		{near2 / w,         0,         0,  0},
		{0,         near2 / h,         0,  0},
		{0,                 0,      clip, -1},
		{0,                 0, nz * clip,  0}
	}});
}
