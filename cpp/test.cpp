#include "ft_vector.h"
#include <stdio.h>
using namespace ft;

int		main(int argc, char **argv)
{
	auto m = ft::Vector(1,2,3);
	printf("%f %f %f\n", m.x, m.y, m.z);
	printf("zero == %d\n", m.is_zero());

	m = ft::Vector::zero;
	printf("zero == %d\n", m.is_zero());

	auto a = ft::Vector(10,0,0);
	auto b = ft::Vector(5,0,0);
	printf("a %f %f %f\n", a.x, a.y, a.z);
	printf("b %f %f %f\n", b.x, b.y, b.z);

	auto c = (b - a);
	std::cout << "c " << c << std::endl;

	printf("parallel %d\n", Vector::are_parallel(a, b));

	a = Vector::unitX;
	b = Vector::unitZ;
	std::cout << a << b << std::endl;

	auto ang = Vector::angle_between(a, b);
	printf("ang %f\n", ang * RAD_TO_DEG);
	printf("parallel %d\n", Vector::are_parallel(a, b));

}
