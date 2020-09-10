/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_mul.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:30:03 by ngontjar          #+#    #+#             */
/*   Updated: 2020/09/11 02:44:50 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** https://www.mathsisfun.com/algebra/matrix-multiplying.html
** *
** (x,y) are for the current cell in the resulting matrix.
** The cell is initialized to 0.
** Cell = A(row) · B(col)
*/

t_matrix	mat_mul(t_matrix a, t_matrix b)
{
	t_matrix	matrix;
	int			x;
	int			y;
	int			i;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			matrix.m[y][x] = 0;
			i = 0;
			while (i < 4)
			{
				matrix.m[y][x] += (a.m[y][i] * b.m[i][x]);
				++i;
			}
			++x;
		}
		++y;
	}
	return (matrix);
}
