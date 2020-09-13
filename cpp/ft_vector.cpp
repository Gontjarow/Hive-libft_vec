#include "ft_vector.h"

namespace ft
{
	// Static
	Vector	Vector::zero = Vector();
	Vector	Vector::unitX = Vector(1, 0, 0);
	Vector	Vector::unitY = Vector(0, 1, 0);
	Vector	Vector::unitZ = Vector(0, 0, 1);

	double	Vector::angle_between(const Vector& l, const Vector& r)
	{
		double cosine = (l.normalize() * r.normalize());
		if (cosine >= 1.0)
			return (0.0);
		else if (cosine <= -1.0)
			return (M_PI);
		else
			return acos(cosine);
	}

	bool	Vector::are_parallel(const Vector& l, const Vector& r)
	{
		double dot = l.normalize() * r.normalize();
		return (1.0 - std::abs(dot) < Vector::tolerance);
	}

	// Nonstatic
	bool	Vector::is_zero() const
	{
		return (x == 0 && y == 0 && z == 0);
	}

	bool	Vector::is_unit() const
	{
		return (magnitude() == 1.0);
	}

	double	Vector::magnitude() const
	{
		return std::sqrt(dot());
	}

	Vector	Vector::normalize() const
	{
		return (*this / magnitude());
	}

	Vector	Vector::add(const Vector& r) const
	{
		return (*this + r);
	}

	Vector	Vector::sub(const Vector& r) const
	{
		return (*this - r);
	}

	Vector	Vector::multiply(double scalar) const
	{
		return (*this * scalar);
	}

	Vector	Vector::divide(double scalar) const
	{
		return (*this / scalar);
	}

	double	Vector::dot() const
	{
		return (x*x + y*y + z*z);
	}

	double	Vector::dot(const Vector& r) const
	{
		return (x*r.x + y*r.y + z*r.z);
	}

	Vector	Vector::cross(const Vector& r) const
	{
		return Vector(
			y * r.z - z * r.y,
			x * r.z - z * r.x,
			x * r.y - y * r.x);
	}

	double	Vector::cross2D(const Vector& r) const
	{
		return (x * r.y - y * r.x);
	}

	double	Vector::distance(const Vector& l, const Vector& r) const
	{
		return (l - r).magnitude();
	}

	double	Vector::distance(const Vector& r) const
	{
		return (*this - r).magnitude();
	}

	// Basic operators
	// Note: vector * vector = dot product
	// Note: vector % vector = cross product
	// Todo: multiply by quaternion to rotate

	Vector	Vector::operator + (const Vector &r) const
	{
		return Vector(x + r.x, y + r.y, z + r.z);
	}

	Vector	Vector::operator - (const Vector &r) const
	{
		return Vector(x - r.x, y - r.y, z - r.z);
	}

	double	Vector::operator * (const Vector &r) const
	{
		return dot(r);
	}

	Vector	Vector::operator % (const Vector &r) const
	{
		return cross(r);
	}

	Vector	Vector::operator + (const double &r) const
	{
		return Vector(x + r, y + r, z + r);
	}

	Vector	Vector::operator - (const double &r) const
	{
		return Vector(x - r, y - r, z - r);
	}

	Vector	Vector::operator * (const double &r) const
	{
		return Vector(x * r, y * r, z * r);
	}

	Vector	Vector::operator / (const double &r) const
	{
		return Vector(x / r, y / r, z / r);
	}

	Vector Vector::operator * (const Matrix &r) const
	{
		// Fully applies RHS matrix to LHS vector.
		return Vector(
			this->x * r.m[0][0] +
			this->y * r.m[1][0] +
			this->z * r.m[2][0] + r.m[3][0],

			this->x * r.m[0][1] +
			this->y * r.m[1][1] +
			this->z * r.m[2][1] + r.m[3][1],

			this->x * r.m[0][2] +
			this->y * r.m[1][2] +
			this->z * r.m[2][2] + r.m[3][2]);
	}

	// Shorthand assignments

	Vector&	Vector::operator  = (const Vector &r)
	{
		x = r.x;
		y = r.y;
		z = r.z;
		return *this;
	}

	Vector&	Vector::operator += (const Vector &r)
	{
		x += r.x;
		y += r.y;
		z += r.z;
		return *this;
	}

	Vector&	Vector::operator -= (const Vector &r)
	{
		x -= r.x;
		y -= r.y;
		z -= r.z;
		return *this;
	}

	Vector&	Vector::operator += (const double &r)
	{
		x += r;
		y += r;
		z += r;
		return *this;
	}

	Vector&	Vector::operator -= (const double &r)
	{
		x -= r;
		y -= r;
		z -= r;
		return *this;
	}

	Vector&	Vector::operator *= (const double &r)
	{
		x *= r;
		y *= r;
		z *= r;
		return *this;
	}

	Vector&	Vector::operator /= (const double &r)
	{
		x /= r;
		y /= r;
		z /= r;
		return *this;
	}

	Vector& Vector::operator *= (const Matrix &r)
	{
		// Fully applies RHS matrix to LHS vector.
		this->x * r.m[0][0] +
		this->y * r.m[1][0] +
		this->z * r.m[2][0] + r.m[3][0];

		this->x * r.m[0][1] +
		this->y * r.m[1][1] +
		this->z * r.m[2][1] + r.m[3][1];

		this->x * r.m[0][2] +
		this->y * r.m[1][2] +
		this->z * r.m[2][2] + r.m[3][2];
		return (*this);
	}

	// http://realtimecollisiondetection.net/blog/?p=89

	bool	Vector::operator == (const Vector &r) const
	{
		double tx = std::max(std::abs(x), std::abs(r.x));
		double ty = std::max(std::abs(y), std::abs(r.y));
		double tz = std::max(std::abs(z), std::abs(r.z));
		tx = tolerance * std::max(1.0, tx);
		ty = tolerance * std::max(1.0, ty);
		tz = tolerance * std::max(1.0, tz);

		return (std::abs(x - r.x) <= tx
			&& (std::abs(y - r.y) <= ty)
			&& (std::abs(z - r.z) <= tz));
	}

	bool	Vector::operator != (const Vector &r) const
	{
		return !(*this == r);
	}

	// Pretty print, formatted output

	std::ostream&	operator << (std::ostream &stream, Vector const &v)
	{
		char buf[256];
		std::sprintf(buf, "{\033[1;31m%.3f\033[0m, \033[1;32m%.3f\033[0m, \033[1;34m%.3f\033[0m, %.3f}", v.x, v.y, v.z, v.w);
		return (stream << buf);
	}
}
