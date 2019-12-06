#include "ft_math.h"

void matrix_identity(t_matrix *mat)
{
	memset(mat, 0, sizeof(t_matrix));
	mat->m[0][0] = 1;
	mat->m[1][1] = 1;
	mat->m[2][2] = 1;
	mat->m[3][3] = 1;
}
