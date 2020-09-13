#pragma once

#include <stdio.h>
#include <cstdio>	// sprintf
#include <iostream>	// cout

namespace ft
{
	struct Vector;

	struct Matrix
	{
		double m[4][4];

		Matrix operator * (const Matrix &r) const;

		Matrix& operator *= (const Matrix &r);

		friend std::ostream& operator << (std::ostream &stream, Matrix const &v);

		Matrix() : m {
			{1,0,0,0},
			{0,1,0,0},
			{0,0,1,0},
			{0,0,0,1}}
		{}
	};
}
