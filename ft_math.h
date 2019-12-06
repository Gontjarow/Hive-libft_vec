/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:22:21 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/06 17:07:56 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include "math.h"
# include "string.h"

# define PI (3.1415926535897932384626433832795f)
# define PI_BY_TWO (1.5707963267948966192313216916398f)
# define TWO_PI (6.283185307179586476925286766559f)

# define RAD_TO_DEG (57.295779513082320876798154814105f)
# define DEG_TO_RAD (0.017453292519943295769236907684886f)

# define SQRT2 (1.4142135623730950488016887242097f)
# define SQRT6 (2.4494897427831780981972840747058f)

typedef struct	s_matrix
{
	double m[4][4];
}				t_matrix;

typedef struct	s_xy
{
	double x;
	double y;
}				t_xy;

typedef struct	s_xyz
{
	double x;
	double y;
	double z;
}				t_xyz;

typedef struct	s_xyzw
{
	double x;
	double y;
	double z;
	double w;
}				t_xyzw;

void			matrix_identity(t_matrix *mat);

void			matrix_vector(t_matrix mat, t_xyz *out);
void			vector_matrix(t_xyz vector, t_matrix *out);
void			axang_matrix(t_xyzw r, t_matrix *out);

void			matrix_multiply(t_matrix a, t_matrix b, t_matrix *out);
void			matrix_transpose(t_matrix *mat, t_matrix *out);
void			vector_rotate(t_xyz p, t_matrix mat, t_xyz *out);

#endif
