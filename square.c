#include "minirt.h"

typedef struct s_square
{
	t_vec3	*center;
	t_vec3	*normal;
	double	len;
	int	color;
}		t_square;

void	ft_square_touch(t_ray *r, int *color)
{
	t_square	sq;
	t_vec3		*abs_up;
	t_vec3		*up;
	t_vec3		*right;
	t_vec3		*tmp;
	t_vec3		*v1;
	t_vec3		*v2;
	t_vec3		*v3;
	t_vec3		*v4;
	t_a16		*m;
	t_a16		*m_inverse;
	double		beta;
	double		gamma;
	double		t;

	sq.center = ft_vec3(0.0, 0.0, -3.0);
	sq.normal = ft_vec3(0.0, 0.0, -1.0);
	sq.len	= 0.5;
	abs_up = ft_vec3(0.0, 1.0, 0.0);
	right = ft_vec3_cross_product(*sq.normal, *abs_up);
	up = ft_vec3_cross_product(*sq.normal, *right);
	tmp = right;
	right = ft_vec3_normalize(*right);
	free(tmp);
	tmp = up;
	up = ft_vec3_normalize(*up);
	free(tmp);
	v1 = ft_vec3_remove(*sq.center, *up);
	v2 = ft_vec3_remove(*sq.center, *right);
	v3 = ft_vec3_remove(*sq.center, *r->e);
	m = ft_matrix(*v1, *v2, *r->d);
	m_inverse = ft_matrix_inverse(*m, ft_matrix_determinant(*m));
	ft_puta16(*m);
	v4 = ft_vec3_transform_normal(*m_inverse, *v3);
	beta = (*v4)[0];
	gamma = (*v4)[1];
	t = (*v4)[2];
	sq.color = 0xa0e5e5;
	if ((beta >= sq.len / -2 && beta <= sq.len / 2) && (gamma >= sq.len / -2 && gamma <= sq.len / 2))
	{
		printf("beta = %f gamma %f t %f\n", beta, gamma, t);
		if((r->t > 0 & t < r->t) || (r->t <= 0))
		{
			*color = sq.color;
			r->t = t;
		}
	}
	free(sq.center);
	free(sq.normal);
	free(abs_up);
	free(up);
	free(right);
	free(v1);
	free(v2);
	free(v3);
	free(v4);
	free(m);
	free(m_inverse);
}
