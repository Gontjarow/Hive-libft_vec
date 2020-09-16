/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <niko.gontjarow@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:22:21 by ngontjar          #+#    #+#             */
/*   Updated: 2020/09/16 14:46:26 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include "math.h"

# define PI 3.14159265358979323846264338327950288
# define PI_BY_TWO 1.57079632679489661923132169163975144
# define TWO_PI 6.28318530717958647692528676655900576

# define RAD_TO_DEG 57.29577951308232087679815481410517033
# define DEG_TO_RAD 0.01745329251994329576923690768488612

# define SQRT2 1.41421356237309504880168872420969807
# define SIN45_DEG 0.70710678118654752440084436210484903

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

typedef t_xyzw	t_rotation;
typedef t_xyz	t_euler;
typedef double	t_deg;
typedef double	t_rad;

/*
** Constructors?
** Maybe some of these should be #defines instead.
*/

# define VEC2(a,b) (t_xy){a,b}
# define VEC3(a,b,c) (t_xyz){a,b,c}
# define VEC4(a,b,c,d) (t_xyzw){a,b,c,d}

t_matrix		mat_identity(void);
t_matrix		mat_new_axang(t_xyz ax, double ang);
t_matrix		mat_new_rotx(t_rad angle);
t_matrix		mat_new_roty(t_rad angle);
t_matrix		mat_new_rotz(t_rad angle);
t_matrix		mat_new_rot2d(t_rad angle);
t_matrix		mat_new_scale(double x, double y, double z);
t_matrix		mat_new_scale_center(double x, double y, double z, t_xyz p);
t_matrix		mat_new_translation(double x, double y, double z);

t_matrix		mat_persp_fov(double ar, double nz, double fz, t_deg vfov);
t_matrix		mat_persp_fov2(t_deg fov, double near, double far);
t_matrix		mat_persp_ortho(double w, double h, double nz, double fz);
t_matrix		mat_persp_ortho2(t_xy v, t_xy h, t_xy d);
t_matrix		mat_persp_wh(double w, double h, double nz, double fz);

/*
** Conversion functions
*/

t_xyz			mtov(t_matrix mat);
t_matrix		vtom(t_xyz euler);
t_xyzw			vtoq(t_xyz euler);
t_xyz			qtov(t_rotation q);
t_matrix		qtom(t_rotation q);
t_matrix		atom(t_xyzw r);

/*
** Operations
*/

t_matrix		mat_mul(t_matrix a, t_matrix b);
t_matrix		mat_transpose(t_matrix *mat);
t_matrix		mat_rotate(t_matrix m, t_rotation q);

t_xy			vec2_rot(t_xy v, t_rad angle);

t_xyz			vec3_rot(t_xyz v1, t_xyz v2);
t_xyz			vec3_mulmat(t_xyz p, t_matrix mat);

/*
** Other calculations {todo: categorize these}
*/

t_xy			vec2_add(t_xy a, t_xy b);
t_xy			vec2_sub(t_xy a, t_xy b);
t_xy			vec2_mul(t_xy v, double scalar);
t_xy			vec2_div(t_xy v, double scalar);
t_xy			vec2_norm(t_xy v);

double			vec2_mag(t_xy v);
double			vec2_dot(t_xy a, t_xy b);
double			vec2_cross(t_xy a, t_xy b);

double			vec2_rad(t_xy v);
double			vec2_slope(t_xy p_a, t_xy p_b);
t_xy			vec2_lerp(t_xy a, t_xy b, double t);

t_xyz			vec23(t_xy v);
t_xyzw			vec24(t_xy v);

t_xyz			vec3_add(t_xyz a, t_xyz b);
t_xyz			vec3_sub(t_xyz a, t_xyz b);
t_xyz			vec3_mul(t_xyz v, double scalar);
t_xyz			vec3_div(t_xyz v, double scalar);
t_xyz			vec3_norm(t_xyz v);

double			vec3_mag(t_xyz v);
double			vec3_dot(t_xyz a, t_xyz b);
t_xyz			vec3_cross(t_xyz a, t_xyz b);

double			vec3_dist(t_xyz a, t_xyz b);

t_xy			vec32(t_xyz v);
t_xyzw			vec34(t_xyz v);

t_rotation		rot_norm(t_rotation q);
double			rot_mag(t_rotation q);
t_rotation		rot_between(t_xyz a, t_xyz b);

t_xyzw			vec4_mulmat(t_xyzw p, t_matrix mat);

t_xy			vec42(t_xyzw v);
t_xyz			vec43(t_xyzw v);

#endif
