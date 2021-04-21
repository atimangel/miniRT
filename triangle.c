#include "minirt.h"

typedef struct s_triangle
{
	t_vec3	*o;
	t_vec3	*p1;
	t_vec3	*p2;
	int	color;
}		t_triangle;

void	ft_triangle_touch(t_ray *r, int *color)
{
	t_triangle	tr;
	t_vec3		*v1;
	t_vec3		*v2;
	t_vec3		*v3;
	t_vec3		*v4;
	t_a16		*m;
	t_a16		*m_inverse;
	double		beta;
	double		gamma;
	double		t;

	tr.o = ft_vec3(0.0, 0.0, -7.0);
	tr.p1 = ft_vec3(0.0, 7.0, -7.0);
	tr.p2 = ft_vec3(7.0, 0.0, -7.0);
	tr.color = 0x9000;
	v1 = ft_vec3_remove(*tr.o, *tr.p1);
	v2 = ft_vec3_remove(*tr.o, *tr.p2);
	v3 = ft_vec3_remove(*tr.o, *r->e);
	m = ft_matrix(*v1, *v2, *r->d);
	m_inverse = ft_matrix_inverse(*m, ft_matrix_determinant(*m));
	v4 = ft_vec3_transform_normal(*m_inverse, *v3);
	beta = (*v4)[0];
	gamma = (*v4)[1];
	t = (*v4)[2];
	if ((beta >= 0 && beta <= 1) && (gamma >= 0 && gamma <= 1)
			&& (beta+ gamma <= 1))
	{
		printf("beta %.2f, gamma %.2f, t %.2f\n", beta, gamma, t);
		if ((r->t > 0 && t < r->t) || (r->t <= 0))
		{
			*color = tr.color;
			r->t = t;
		}
	}
	free(v1);
	free(v2);
	free(v3);
	free(v4);
	free(m);
	free(m_inverse);
}
