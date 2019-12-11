/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiply.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:30:03 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/11 22:15:06 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

t_matrix	mat_multiply(t_matrix a, t_matrix b)
{
	t_matrix	matrix;
	int			y;
	int			x;
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