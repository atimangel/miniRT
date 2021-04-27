#include "minirt.h"

typedef struct s_triangle
{
	t_vec3	*o;
	t_vec3	*p1;
	t_vec3	*p2;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}		t_triangle;

void	ft_make_triangle(t_triangle *tr)
{
	tr->o = ft_vec3(0.0, 0.0, -7.0);
	tr->p1 = ft_vec3(0.0, 7.0, -7.0);
	tr->p2 = ft_vec3(7.0, 0.0, -7.0);
	tr->r = 0;
	tr->g = 0x90;
	tr->b = 0;
	
}

t_vec3	*ft_triangle_interaction(t_triangle tr, t_ray *r, t_vec3 **n)
{
	t_vec3	*side1;
	t_vec3	*side2;
	t_vec3	*v1;
	t_a16	*m;
	t_a16	*m_inverse;
	t_vec3	*tmp;

	side1 = ft_vec3_remove(*tr.o, *tr.p1);
	side2 = ft_vec3_remove(*tr.o, *tr.p2);
	*n = ft_vec3_cross_product(*side1, *side2);
	if (ft_vec3_dot_product(**n, *r->d) < 0)
	{
		tmp = *n;
		*n = ft_vec3_scale(*tmp, -1);
		free(tmp);
	}
	v1 = ft_vec3_remove(*tr.o, *r->e);
	m = ft_matrix(*side1, *side2, *r->d);
	m_inverse = ft_matrix_inverse(*m, ft_matrix_determinant(*m));
	free(side1);
	free(side2);
	free(m);
	side1 = ft_vec3_transform_normal(*m_inverse, *v1);
	free(m_inverse);
	free(v1);
	return (side1);
}
void	ft_triangle_touch(t_ray *r, t_pixel_unit *u)
{
	t_triangle	tr;
	double		beta;
	double		gamma;
	double		t;
	t_vec3		*v;
	t_vec3		*n;

	ft_make_triangle(&tr);
	v = ft_triangle_interaction(tr, r, &n);
	beta = (*v)[0];
	gamma = (*v)[1];
	t = (*v)[2];
	if ((beta >= 0 && beta <= 1) && (gamma >= 0 && gamma <= 1)
			&& (beta + gamma <= 1) && ft_vec3_dot_product(*n, *r->d) != 0)
	{
		if ((r->t > 0 && t < r->t) || (r->t <= 0))
		{
			u->o_r = tr.r;
			u->o_g = tr.g;
			u->o_b = tr.b;
			if (u->o_n != 0)
				free(u->o_n);
			u->o_n = n;
			r->t = t;
		}
	}
	free(tr.o);
	free(tr.p1);
	free(tr.p2);
	if (u->o_n != n)
		free(n);
	free(v);
}
