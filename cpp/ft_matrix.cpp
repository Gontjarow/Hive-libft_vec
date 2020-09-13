#include "ft_matrix.h"

namespace ft
{
	Matrix	Matrix::operator * (const Matrix &r) const
	{
		Matrix result;
		for (int y = 0; y < 4; ++y)
		for (int x = 0; x < 4; ++x)
		{
			result.m[y][x] =
				this->m[y][0] * r.m[0][x] +
				this->m[y][1] * r.m[1][x] +
				this->m[y][2] * r.m[2][x] +
				this->m[y][3] * r.m[3][x];
		}
		return (result);
	}

	Matrix&	Matrix::operator *= (const Matrix &r)
	{
		Matrix result;
		for (int y = 0; y < 4; ++y)
		for (int x = 0; x < 4; ++x)
		{
			result.m[y][x] =
				this->m[y][0] * r.m[0][x] +
				this->m[y][1] * r.m[1][x] +
				this->m[y][2] * r.m[2][x] +
				this->m[y][3] * r.m[3][x];
		}
		(*this) = result;
		return (*this);
	}

	std::ostream&	operator << (std::ostream &stream, Matrix const &m)
	{
		char buf[1024];
		std::sprintf(buf,
			"{%4.3f | %4.3f | %4.3f | %4.3f}\n"
			"{%4.3f | %4.3f | %4.3f | %4.3f}\n"
			"{%4.3f | %4.3f | %4.3f | %4.3f}\n"
			"{%4.3f | %4.3f | %4.3f | %4.3f}",
			m.m[0][0], m.m[0][1], m.m[0][2], m.m[0][3],
			m.m[1][0], m.m[1][1], m.m[1][2], m.m[1][3],
			m.m[2][0], m.m[2][1], m.m[2][2], m.m[2][3],
			m.m[3][0], m.m[3][1], m.m[3][2], m.m[3][3]);
		return (stream << buf);
	}
}
