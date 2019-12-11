/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_persp_wh.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:24:57 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/11 21:38:56 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** Creates a matrix for perspective projection from nearZ dimensions.
** w & h = view width/height dimensions
** nearZ & farZ = clipping
*/

t_matrix	mat_persp_wh(double w, double h, double nearZ, double farZ)
{
	double near2;
	double clip;

	if (nearZ <= 0 || farZ <= 0 || nearZ >= farZ)
		return (matrix_identity());
	near2 = nearZ * 2;
	clip = farZ / (nearZ - farZ);
	return ((t_matrix){
		.m[0][0] = near2 / w, .m[0][1] = 0, .m[0][2] = 0, .m[0][3] = 0,
		.m[1][0] = 0, .m[1][1] = near2 / h, .m[1][2] = 0, .m[1][3] = 0,
		.m[2][0] = 0, .m[2][1] = 0, .m[2][2] = clip, .m[2][3] = -1,
		.m[3][0] = 0, .m[3][1] = 0, .m[3][2] = nearZ * clip, .m[3][3] = 0
	});
}
