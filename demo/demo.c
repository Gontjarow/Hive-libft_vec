#include "ft_demo.h"

#include <SDL2/SDL.h>

t_demo demo;


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
void show_vec2(t_xy v)
{
	printf("{ %8.3f | %8.3f }",
		v.x, v.y
	);
}

int in_range(t_xy p, double min, double max)
{
	return (p.x >= min && p.x <= max
		&& (p.y >= min && p.y <= max));
}
void ft_draw(unsigned int *pixel, t_xy start, t_xy end, int color)
{
	t_xy dir = vec2_sub(end, start);

	t_xy abs = VEC2(fabs(dir.x), fabs(dir.y));
	float step = (abs.x > abs.y) ? abs.x : abs.y;
	dir = vec2_div(dir, step);

	show_vec2(dir); printf(" (dir)\n");
	int i = 0;
	while (i <= step)
	{
		SDL_UpdateWindowSurface(demo.win);
		SDL_Delay(10);
		if (in_range(start, 0, WIN_SIZE))
			pixel[(int)(start.x + start.y * WIN_SIZE)] = color;
		start.x += dir.x;
		start.y += dir.y;
		++i;
	}
}

// https://www.songho.ca/opengl/gl_projectionmatrix.html

t_matrix	projection(float w, float h, float n, float f)
{
	return ((t_matrix){.m = {
		{ n/w,    0,             0,               0 },
		{   0,  n/h,             0,               0 },
		{   0,    0,  -(f+n)/(f-n),  -(2*f*n)/(f-n) },
		{   0,    0,            -1,               0 }
	}});
}

int main(int argc, char const *argv[])
{
	// Set up a projection matrix with width/height/near/far frustrum
	// This transforms all points within the frustrum into the range (-1, 1)

	// Note: The points will still have Z and W components, but they will be
	//	in screen coordinates, so only X and Y are needed for drawing.

	// Any points outside of the frustrum will be scaled too, but they will
	// be outside of the range, for example: "-2, 0.5"

	// Attempting to draw these would not make sense, at least for
	// the pixels that fall outside of the window. Some clipping ("clip space")
	// would have to be done.

	t_matrix m = projection(10,10,1,10);
	printf("matrix:\n");
	show_mat(m);

	// Original points
	t_xyzw point[] = {
		VEC4(-1, -1, 1, 1),
		VEC4(-1,  1, 2, 1),
		VEC4( 3, -1, 0, 1),
		VEC4( 1,  1, 0, 1),

		VEC4(-1, -1, 1, 1),
		VEC4(-1,  1, 1, 1),
		VEC4( 1, -1, 1, 1),
		VEC4( 1,  1, 1, 1),
	};

	// Transformed by matrix
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

	// Actual demo init starts here.
	// The window will always be square, according to WIN_SIZE
	// WIN_HALF should be half of WIN_SIZE.

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("Failed to initialize SDL: %s\n", SDL_GetError());
		return 1;
	}

	demo.win = SDL_CreateWindow("Libft Vector Demo",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WIN_SIZE, WIN_SIZE, 0);
	demo.buf = SDL_GetWindowSurface(demo.win);

	if (demo.win == NULL || demo.buf == NULL)
	{
		printf("Failed to initialize SDL: %s\n", SDL_GetError());
		return 1;
	}

	demo.pixel = demo.buf->pixels;
	const Uint8 *key = SDL_GetKeyboardState(NULL);

	// Demo loop starts here.

	uint32_t frame_start;
	uint32_t frame_ticks;
	demo.run = 1;

	while (demo.run)
	{
		// Limit framerate, part 1
		frame_start = SDL_GetTicks();

		if (key[SDL_SCANCODE_ESCAPE] || key[SDL_SCANCODE_SPACE])
		{
			printf("Stop key!\n");
			break;
		}

		while (SDL_PollEvent(&demo.event))
		{
			if (demo.event.type == SDL_WINDOWEVENT
			&& demo.event.window.event == SDL_WINDOWEVENT_CLOSE)
			{
				demo.run = 0;
			}
		}

		// Draw diagonal and horizontal lines with DDA algorithm.
		// ft_draw(demo.pixel, VEC2(20, 20), VEC2(WIN_SIZE-20, WIN_SIZE-20), 0xFFFFFF);
		// ft_draw(demo.pixel, VEC2(WIN_SIZE-20, 20), VEC2(20, WIN_SIZE-20), 0xFFFFFF);
		// ft_draw(demo.pixel, VEC2(WIN_HALF, 20), VEC2(WIN_HALF, WIN_SIZE-20), 0xFFFFFF);
		// ft_draw(demo.pixel, VEC2(20, WIN_HALF), VEC2(WIN_SIZE-20, WIN_HALF), 0xFFFFFF);

		// Draw transformed points (first 4):
		t_xy center = VEC2(WIN_HALF,WIN_HALF);
		t_xy a = vec2_add(center, vec2_mul(VEC2(screen[0].x, screen[0].y), WIN_SIZE));
		t_xy b = vec2_add(center, vec2_mul(VEC2(screen[1].x, screen[1].y), WIN_SIZE));
		t_xy c = vec2_add(center, vec2_mul(VEC2(screen[2].x, screen[2].y), WIN_SIZE));
		t_xy d = vec2_add(center, vec2_mul(VEC2(screen[3].x, screen[3].y), WIN_SIZE));

		printf("draw\n");
		show_vec2(a); printf(" ----> "); show_vec2(b); printf(" (red)\n");
		ft_draw(demo.pixel, a, b, 0xFF0000);
		show_vec2(b); printf(" ----> "); show_vec2(c); printf(" (green)\n"); // TODO: Bug!
		ft_draw(demo.pixel, b, c, 0x00FF00);
		show_vec2(c); printf(" ----> "); show_vec2(d); printf(" (blue)\n");
		ft_draw(demo.pixel, c, d, 0x0000FF);
		show_vec2(d); printf(" ----> "); show_vec2(a); printf(" (white)\n");
		ft_draw(demo.pixel, d, a, 0xFFFFFF);

		SDL_UpdateWindowSurface(demo.win);
		SDL_memset(demo.pixel, 0, demo.buf->h * demo.buf->pitch);

		// Limit framerate, part 2
		frame_ticks = SDL_GetTicks() - frame_start;
		if (frame_ticks < MAX_FRAME_TICKS)
		{
			// printf("Delay: %d\n", MAX_FRAME_TICKS - frame_ticks);
			SDL_Delay(MAX_FRAME_TICKS - frame_ticks);
			// break;
		}
	}
	printf("SDL Quit\n");
	SDL_Quit();
	return 0;
}
