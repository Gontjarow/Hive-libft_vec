#include "ft_demo.h"

#include <SDL2/SDL.h>

void show_mat(t_matrix m)
{
	printf("\n"
		"{ %8.3f | %8.3f | %8.3f | %8.3f }\n"
		"{ %8.3f | %8.3f | %8.3f | %8.3f }\n"
		"{ %8.3f | %8.3f | %8.3f | %8.3f }\n"
		"{ %8.3f | %8.3f | %8.3f | %8.3f }\n",
		m.m[0][0], m.m[0][1], m.m[0][2], m.m[0][3],
		m.m[1][0], m.m[1][1], m.m[1][2], m.m[1][3],
		m.m[2][0], m.m[2][1], m.m[2][2], m.m[2][3],
		m.m[3][0], m.m[3][1], m.m[3][2], m.m[3][3]
	);
}
void show_vec4(t_xyzw v)
{
	printf("{ %8.3f | %8.3f | %8.3f | %8.3f }",
		v.x, v.y, v.z, v.w
	);
}

int main(int argc, char const *argv[])
{
	t_matrix m = mat_persp_fov2(90, 0.1, 10);
	printf("matrix:\n");
	show_mat(m);

	t_xyzw point[] = {
		VEC4(-1, -1, 0, 1),
		VEC4(-1,  1, 0, 1),
		VEC4( 1, -1, 0, 1),
		VEC4( 1,  1, 0, 1),
		VEC4(-1, -1, 1, 1),
		VEC4(-1,  1, 1, 1),
		VEC4( 1, -1, 1, 1),
		VEC4( 1,  1, 1, 1),
	};

	t_xyzw screen[8];
	int i = 0;
	while (i < 8)
	{
		screen[i] = vec4_mulmat(point[i], m);
		++i;
	}

	i = 0; printf("points:\n");
	while (i < 8)
	{
		show_vec4(point[i]);
		printf("\n");
		++i;
	}
	i = 0; printf("screen:\n");
	while (i < 8)
	{
		show_vec4(screen[i]);
		printf("\n");
		++i;
	}

	return 0;
}
