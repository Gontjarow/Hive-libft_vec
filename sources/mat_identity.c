/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_identity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:24:57 by ngontjar          #+#    #+#             */
/*   Updated: 2020/09/11 05:01:18 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** All matrices in this library should follow column-major format.
** However, the identity matrix matches the row-major format as well.
** *
** │ X: │ Y: │ Z: │ W: │    │ F: │ R: │ U: │ T: │
** ┼────┼────┼────┼────┼    ┼────┼────┼────┼────┼
** │ 00 │ 01 │ 02 │ 03 │    │ Fx │ Rx │ Ux │ Tx │
** │ 10 │ 11 │ 12 │ 13 │ or │ Fy │ Ry │ Uy │ Ty │
** │ 20 │ 21 │ 22 │ 23 │    │ Fz │ Rz │ Uz │ Tz │
** │ 30 │ 31 │ 32 │ 33 │    │ Fw │ Rw │ Uw │ Tw │
** *
** The 4th column is the translation-vector.
** The 4th component will usually be 1.
*/

t_matrix	mat_identity(void)
{
	return ((t_matrix){.m = {
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1}
	}});
}
