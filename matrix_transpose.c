#include "ft_math.h"

void matrix_transpose(t_matrix *mat, t_matrix *out)
{
	out->m[0][1] = mat->m[1][0];
	out->m[0][2] = mat->m[2][0];
	;
	out->m[1][0] = mat->m[0][1];
	out->m[1][1] = mat->m[1][1];
	out->m[1][2] = mat->m[2][1];
	;
	out->m[2][0] = mat->m[0][2];
	out->m[2][1] = mat->m[1][2];
}
