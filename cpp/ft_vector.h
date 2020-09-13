#pragma once

#include "ft_matrix.h"

#include <cmath>
#include <cstdio>	// sprintf
#include <iostream>	// cout
// #include <algorithm>
// #include <ostream>

#ifndef DEG_TO_RAD
#define DEG_TO_RAD 0.01745329251994329576923690768488612
#endif

#ifndef RAD_TO_DEG
# define RAD_TO_DEG 57.29577951308232087679815481410517033
#endif

namespace ft
{
	struct Matrix;

	struct Vector
	{
		double x;
		double y;
		double z;
		double w;

		static constexpr double tolerance = 1.0e-15;

		static Vector	zero;
		static Vector	unitX;
		static Vector	unitY;
		static Vector	unitZ;

		static double	angle_between(const Vector& l, const Vector& r);
		static bool		are_parallel(const Vector& l, const Vector& r);

		bool	is_zero() const;
		bool	is_unit() const;

		double	magnitude() const;
		Vector	normalize() const;
		Vector	add(const Vector& r) const;
		Vector	sub(const Vector& r) const;
		Vector	multiply(double scalar) const;
		Vector	divide(double scalar) const;
		double	dot() const;
		double	dot(const Vector& r) const;
		Vector	cross(const Vector& r) const;
		double	cross2D(const Vector& r) const;
		double	distance(const Vector& l, const Vector& r) const;
		double	distance(const Vector& r) const;

		// Basic operators
		// Note: vector * vector = dot product
		// Note: vector % vector = cross product
		Vector operator + (const Vector &r) const;
		Vector operator - (const Vector &r) const;
		double operator * (const Vector &r) const;
		Vector operator % (const Vector &r) const;
		Vector operator + (const double &r) const;
		Vector operator - (const double &r) const;
		Vector operator * (const double &r) const;
		Vector operator / (const double &r) const;
		Vector operator * (const Matrix &r) const;

		Vector& operator  = (const Vector &r);
		Vector& operator += (const Vector &r);
		Vector& operator -= (const Vector &r);
		Vector& operator += (const double &r);
		Vector& operator -= (const double &r);
		Vector& operator *= (const double &r);
		Vector& operator /= (const double &r);

		bool operator == (const Vector &r) const;
		bool operator != (const Vector &r) const;

		friend std::ostream& operator << (std::ostream &stream, Vector const &v);

		Vector()
			: x(0), y(0), z(0), w(1) {}
		Vector(double _x, double _y)
			: x(_x), y(_y), z(0), w(1) {}
		Vector(double _x, double _y, double _z)
			: x(_x), y(_y), z(_z), w(1) {}
		Vector(const Vector& v)
			: x(v.x), y(v.y), z(v.z), w(v.w) {}
	};
}