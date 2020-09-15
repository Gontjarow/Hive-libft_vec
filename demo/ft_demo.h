#ifndef FT_DEMO_H
# define FT_DEMO_H

# include "ft_math.h"

# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>

// Framerate control (~62 FPS)
# include <time.h>
# define MAX_FRAME_TICKS 16
// Printf
# include <stdio.h>

# define WIN_SIZE 500
# define WIN_HALF 250

typedef struct	s_demo
{
	SDL_Window		*win;
	SDL_Surface		*buf;
	unsigned int	*pixel;
	union SDL_Event	event;
	int				run;
}				t_demo;


#endif
