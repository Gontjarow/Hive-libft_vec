/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_mulmat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 21:56:20 by ngontjar          #+#    #+#             */
/*   Updated: 2020/09/14 23:02:18 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** Transform vector V by a given matrix.
** *
** Normally: Matrix row(A) * col(B) = new M
** Where: A(x,y) and B(y,z) ... "width, height"
** We have: M(4,4) and V(4,1) in column-major format
** *
** v.x == v[0][0], v.y == v[1][0], v.z == v[2][0], v.w == v[3][0]
** (The first index is column, the second index is row.)
** *
** Reference: http://matrixmultiplication.xyz/
*/

t_xyzw	vec4_mulmat(t_xyzw v, t_matrix mat)
{
	return ((t_xyzw){
		mat.m[0][0] * v.x +
		mat.m[0][1] * v.y +
		mat.m[0][2] * v.z +
		mat.m[0][3] * v.w,
		mat.m[1][0] * v.x +
		mat.m[1][1] * v.y +
		mat.m[1][2] * v.z +
		mat.m[1][3] * v.w,
		mat.m[2][0] * v.x +
		mat.m[2][1] * v.y +
		mat.m[2][2] * v.z +
		mat.m[2][3] * v.w,
		mat.m[3][0] * v.x +
		mat.m[3][1] * v.y +
		mat.m[3][2] * v.z +
		mat.m[3][3] * v.w
	});
}
