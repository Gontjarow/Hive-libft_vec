/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:22:21 by ngontjar          #+#    #+#             */
/*   Updated: 2019/12/08 01:13:27 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include "math.h"
# include "string.h"

# define PI (3.14159265358979323846264338327950288)
# define PI_BY_TWO (1.57079632679489661923132169163975144)
# define TWO_PI (6.28318530717958647692528676655900576)

# define RAD_TO_DEG (57.29577951308232087679815481410517033)
# define DEG_TO_RAD (0.01745329251994329576923690768488612)

# define SQRT2 (1.41421356237309504880168872420969807)
# define SIN45_DEG (0.70710678118654752440084436210484903)

# define ZERO_ROTATION (t_xyzw){0,0,0,1}
# define ZERO_VECTOR3 (t_xyz){0,0,0}
# define ZERO_VECTOR2 (t_xyz){0,0}

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

/*
** Constructors?
** Maybe some of these should be #defines instead.
*/

# define VEC2(a,b) (t_xy){a,b}
# define VEC3(a,b,c) (t_xyz){a,b,c}
# define VEC4(a,b,c,d) (t_xyz){a,b,c,d}
t_matrix		matrix_identity(void);
t_matrix		matrix_translation(double x, double y, double z);

/*
** Conversion functions
*/

t_xyz			mtov(t_matrix mat);

t_matrix		vtom(t_xyz euler);
t_xyzw			vtoq(t_xyz euler);

t_xyz			qtov(t_xyzw q);
t_matrix		qtom(t_xyzw q);

t_matrix		atom(t_xyzw r);

/*
** Operations
*/

t_matrix		matrix_multiply(t_matrix a, t_matrix b);
t_matrix		matrix_transpose(t_matrix *mat);
t_xyz			vec3_rotate(t_xyz p, t_matrix mat);

/*
** Other calculations {todo: categorize these}
*/

t_xyz			vec3_add(t_xyz a, t_xyz b);
t_xyz			vec3_sub(t_xyz a, t_xyz b);
t_xyz			vec3_mult(t_xyz v, double scalar);
t_xyz			vec3_div(t_xyz v, double scalar);
t_xyz			vec3_norm(t_xyz v);
t_xyz			vec3_cross(t_xyz a, t_xyz b);
double			vec3_dot(t_xyz a, t_xyz b);
double			vec3_mag(t_xyz v);
double			vec3_dist(t_xyz a, t_xyz b);
t_xyzw			quat_norm(t_xyzw q);

#endif
