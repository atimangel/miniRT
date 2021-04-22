#include "minirt.h"

typedef struct s_cylinder
{
	t_vec3	*c;
	t_vec3	*n;
	double	r;
	double	h;
	int		color;
	t_vec3	*c2;
}				t_cylinder;

void	ft_cylinder_touch(t_ray *r, int *color)
{
	t_cylinder	cy;
	double		a;
	double		b;
	double		c;
	double		t;
	double		alpha;
	double		n_dot;
	t_vec3		*tmp;
	t_vec3		*abs_u;
	t_vec3		*u;
	t_vec3		*ri;
	t_vec3		*k;
	double		beta;
	double		gamma;
	t_vec3		*v1;
	t_vec3		*v2;
	t_vec3		*v3;
	t_a16		*m;
	t_a16		*m_inverse;

	cy.c = ft_vec3(0.0, -1.0, -5.0);
	cy.n = ft_vec3(0.0, 0.0, 1.0);
	cy.r = 1.0;
	cy.h = 5.0;
	tmp = ft_vec3_scale(*cy.n, cy.h);
	cy.c2 = ft_vec3_add(*cy.c, *tmp);
	free(tmp);
	k = ft_vec3_remove(*r->e, *cy.c);
	n_dot = ft_vec3_dot_product(*cy.n, *cy.n);
	a = ft_vec3_dot_product(*r->d, *r->d) - pow(ft_vec3_dot_product(*r->d, *cy.n), 2) / n_dot;
	b = 2 * (ft_vec3_dot_product(*r->d, *k) - ft_vec3_dot_product(*r->d, *cy.n) * ft_vec3_dot_product(*k, *cy.n) / n_dot);
	c = ft_vec3_dot_product(*k, *k) - pow(ft_vec3_dot_product(*k, *cy.n), 2) / n_dot - pow(cy.r, 2.0);
	abs_u = ft_vec3(0.0, 1.0, 0.0);
	ri = ft_vec3_cross_product(*cy.c, *abs_u);
	tmp = ri;
	ri = ft_vec3_normalize(*ri);
	free(tmp);
	u = ft_vec3_cross_product(*cy.c,*ri);
	tmp = u;
	u = ft_vec3_normalize(*u);
	free(u);
	if (pow(b, 2.0) - 4 * a * c < 0)
		t = -1;
	if ((t = (-b - sqrt(pow(b, 2.0) - 4 * a * c) / (2 * a)) > 0) && ((r->t > 0 && t < r->t) || r->t <= 0))
	{
		alpha = (ft_vec3_dot_product(*k, *cy.n) + ft_vec3_dot_product(*r->d, *cy.n))/ n_dot;
		if (alpha >= 0 && alpha <= cy.h)
		{
			r->t = t;
			*color = 0x123456;
		}
	}
	else if ((t = (-b + sqrt(pow(b, 2.0) - 4 * a * c) / (2 * a)) > 0) && ((r->t > 0 && t < r->t) || r->t <= 0))
	{
		alpha = (ft_vec3_dot_product(*k, *cy.n) + ft_vec3_dot_product(*r->d, *cy.n))/ n_dot;
		if (alpha >= 0 && alpha <= cy.h)
		{
			r->t = t;
			*color = 0x654321;
		}
	}
	v1 = ft_vec3_remove(*cy.c, *r->e);
	v2 = ft_vec3_remove(*cy.c2, *r->e);
	m = ft_matrix(*u, *ri, *r->d);
	m_inverse = ft_matrix_inverse(*m, ft_matrix_determinant(*m));
	v3 = ft_vec3_transform_normal(*m_inverse, *v1);
	beta = (*v3)[0];
	gamma = (*v3)[1];
	t = (*v3)[2];
	if (beta > cy.r && beta < cy.r && gamma > cy.r && gamma < cy.r)
	{
		if ((r->t > 0 && t < r->t) || r->t <= 0)
		{
			r->t = t;
			*color = 0xabcdef;
		}
	}
	free(v3);
	v3 = ft_vec3_transform_normal(*m_inverse, *v1);
	beta = (*v3)[0];
	gamma = (*v3)[1];
	t = (*v3)[2];
	if (beta > cy.r && beta < cy.r && gamma > cy.r && gamma < cy.r)
	{
		if ((r->t > 0 && t < r->t) || r->t <= 0)
		{
			r->t = t;
			*color = 0xfedcba;
		}
	}
	/*
	free(cy.c);
	free(cy.n);
	free(tmp);
	free(abs_u);
	free(u);
	free(ri);
	free(k);
	free(v1);
	free(v2);
	free(v3);
	free(m);
	free(m_inverse);*/
}
