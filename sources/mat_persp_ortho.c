/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_persp_ortho.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:24:57 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/13 19:10:43 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** Creates a matrix for orthographic projection from nz dimensions.
** w & h = view width/height dimensions
** nz & fz = clipping
*/

t_matrix	mat_persp_ortho(double w, double h, double nz, double fz)
{
	double clip;

	if (nz <= 0 || fz <= 0 || nz >= fz)
		return (mat_identity());
	clip = nz - fz;
	return ((t_matrix){
		.m[0][0] = 2 / w, .m[0][1] = 0, .m[0][2] = 0, .m[0][3] = 0,
		.m[1][0] = 0, .m[1][1] = 2 / h, .m[1][2] = 0, .m[1][3] = 0,
		.m[2][0] = 0, .m[2][1] = 0, .m[2][2] = 1 / clip, .m[2][3] = 0,
		.m[3][0] = 0, .m[3][1] = 0, .m[3][2] = nz / clip, .m[3][3] = 1
	});
}
