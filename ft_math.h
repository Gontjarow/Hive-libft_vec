#ifndef FT_VECTORS
# define FT_VECTORS

# include "math.h"
# include "string.h"

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

void	matrix_identity(t_matrix *mat);

void 	matrix_vector(t_matrix mat, t_xyz *out);
void	vector_matrix(t_xyz vector, t_matrix  *out);

void 	matrix_multiply(t_matrix a, t_matrix b, t_matrix *out);
void 	matrix_transpose(t_matrix *mat, t_matrix *out);
void 	vector_rotate(t_xyz p, t_matrix mat, t_xyz *out);

#endif
