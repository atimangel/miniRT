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

void	ft_make_cylinder(t_cylinder *cy)
{
	t_vec3	*tmp;

	cy->c = ft_vec3(0.0, 10.0, -50.0);
	cy->n = ft_vec3(0.0, 1.0, 0.0);
	cy->r = 10.0;
	cy->h = 20.0;
	cy->color = 0x0000ab;
	tmp = ft_vec3_scale(*cy->n, cy->h);
	cy->c2 = ft_vec3_add(*cy->n, *tmp);
	free(tmp);
	tmp = cy->n;
	cy->n = ft_vec3_normalize(*cy->n);
	free(tmp);
}
void	ft_cylinder_touch_side(t_ray *r, t_cylinder cy, int *color)
{
	double	a;
	double	b;
	double	c;
	double	t;
	double	alpha;
	t_vec3	*ce;	

	t = -1.0;
	ce = ft_vec3_remove(*r->e, *cy.c);
	a = pow(ft_vec3_dot_product(*r->d, *cy.n), 2) - ft_vec3_dot_product(*r->d, *r->d);
	b = ft_vec3_dot_product(*r->d, *cy.n) * ft_vec3_dot_product(*ce, *cy.n) - ft_vec3_dot_product(*ce, *r->d);
	c = pow(cy.r, 2.0) - ft_vec3_dot_product(*ce, *ce) + pow(ft_vec3_dot_product(*ce, *cy.n), 2);
	alpha = -1.0;
	if (pow(b, 2.0) - a * c < 0)
		t = -1.0;
	else
	{
		if ((t = (-b + sqrt(pow(b, 2.0) - a * c)) /  a) >= 0 &&
				((r->t > 0 && t < r->t) || r->t <= 0))
			{
			alpha = ft_vec3_dot_product(*ce, *cy.n) + t * ft_vec3_dot_product(*r->d, *cy.n);
			if (alpha >= 0 && alpha <= cy.h)
			{
				r->t = t;
				*color = cy.color;
				ft_putvec(*r->d);
				ft_putvec(*cy.n);
				printf("1 %f", t);
			}
		}
		if ((t = (-b - sqrt(pow(b, 2.0) - a * c)) / a) > 0 &&
				((r->t > 0 && t < r->t) || r->t <= 0))
		{
			alpha = ft_vec3_dot_product(*ce, *cy.n) + t * ft_vec3_dot_product(*r->d, *cy.n);
			if (alpha >= 0 && alpha <= cy.h)
			{
				r->t = t;
				*color = 0xffffff - cy.color;
				printf("2 %f\n", t);
			}
		}
	}
	free(ce);
}

void	ft_cylinder_touch_circle(t_ray *r, t_cylinder cy, int *color)
{
	
}
void	ft_cylinder_touch(t_ray *r, int *color)
{
	t_cylinder	cy;
	double		t;
	t_vec3		*tmp;
	t_vec3		*abs_u;
	t_vec3		*u;
	t_vec3		*ri;
	double		beta;
	double		gamma;
	t_vec3		*v1;
	t_vec3		*v2;
	t_vec3		*v3;
	t_a16		*m;
	t_a16		*m_inverse;

	ft_make_cylinder(&cy);
	ft_cylinder_touch_side(r, cy, color);
/*	ft_cylinder_touch_circle(r, cy, color)
	abs_u = ft_vec3(0.0, 1.0, 0.0);
	ri = ft_vec3_cross_product(*cy.c, *abs_u);
	tmp = ri;
	ri = ft_vec3_normalize(*ri);
	free(tmp);
	u = ft_vec3_cross_product(*cy.c,*ri);
	tmp = u;
	u = ft_vec3_normalize(*u);
	free(u);*/
/*
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
	}*/
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
