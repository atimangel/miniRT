#include "minirt.h"

typedef struct s_cylinder
{
	t_vec3	*c;
	t_vec3	*n;
	double	r;
	double	h;
	unsigned char red;
	unsigned char green;
	unsigned char blue;
	t_vec3	*c2;
}				t_cylinder;

void	ft_make_cylinder(t_cylinder *cy)
{
	t_vec3	*tmp;

	cy->c = ft_vec3(0.0, 0.0, -50.0);
	cy->n = ft_vec3(0.0, 0.0, 1.0);
	cy->r = 10.0;
	cy->h = 20.0;
	cy->red = 0x00;
	cy->green = 0x00;
	cy->blue = 0xab;
	tmp = ft_vec3_scale(*cy->n, cy->h);
	cy->c2 = ft_vec3_add(*cy->n, *tmp);
	free(tmp);
	tmp = cy->n;
	cy->n = ft_vec3_normalize(*cy->n);
	free(tmp);
}

t_vec3	ft_cylinder_side_normal(t_ray r, t_cylinde cy, double t, double alpha)
{
	t_vec3	*normal;
	t_vec3	*center;
	t_vec3	*point;
	t_vec3	*tmp;

	tmp = ft_vec3_scale(*cy.n, alpha);
	point = ft_vec3_add(*cy.c, *tmp);
	free(tmp);
	tmp = ft_vec3_scale(*r.d, t);
	point = ft_vec3_add(*r.e, *tmp);
	free(tmp);
	//원기둥 밖이랑 안이랑 노말벡터 구하는게 달라야하는뎅... 이건 고정임

}

void	ft_cylinder_touch_side(t_ray *r, t_cylinder cy, t_pixel_unit *u)
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
				u->o_r = cy.red;
				u->o_g = cy.green;
				u->o_b = cy.blue;
				if (u->o_n != 0)
					free(u->o_n);
				if 
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
			}
		}
	}
	free(ce);
}

void	ft_cylinder_touch_circle(t_ray *r, t_cylinder cy, int *color)
{
	t_vec3	*tmp;
	double	t;
	t_vec3	*ec;
	double	radius;
	t_vec3	*cp;

	tmp = ft_vec3_scale(*cy.n, cy.h);
	cy.c2 = ft_vec3_add(*cy.c, *tmp);
	free(tmp);
	ec = ft_vec3_remove(*cy.c, *r->e);
	if ((t = ft_vec3_dot_product(*ec, *cy.n) / ft_vec3_dot_product(*r->d, *cy.n)) > 0 &&
	       ((r->t > 0 && t < r->t)|| r->t <= 0))
	{
		tmp = ft_vec3_scale(*r->d, t);
		cp = ft_vec3_remove(*tmp, *ec);
		free(tmp);
		radius = ft_vec3_len(*cp);
		if (radius >= -cy.r && radius <= cy.r)
		{
			r->t = t;
			if (ft_vec3_dot_product(*cy.n, *r->d) > 0)//outside
				*color = 0x00a000;
			else if (ft_vec3_dot_product(*cy.n, *r->d) < 0)//inside
				*color = 0x00c000;
		}
		free(cp);
	}
	free(ec);
	ec = ft_vec3_remove(*cy.c2, *r->e);
	if ((t = ft_vec3_dot_product(*ec, *cy.n) / ft_vec3_dot_product(*r->d, *cy.n)) > 0 &&
				((r->t > 0 && t < r->t)|| r->t <= 0))//괄호 때문에 2시간 씀
	{
		tmp = ft_vec3_scale(*r->d, t);
		cp = ft_vec3_remove(*tmp, *ec);
		radius = ft_vec3_len(*cp);
		printf(" a/b %f / %f \n",  ft_vec3_dot_product(*ec, *cy.n), ft_vec3_dot_product(*r->d, *cy.n)); 
		printf("rad%f cy_rad%f t %f\n", radius, cy.r, t);
		if (radius >= -cy.r && radius <= cy.r)
		{
			r->t = t;
			if (ft_vec3_dot_product(*cy.n, *r->d) < 0)//outside
				*color = 0x00f0f0;
			else if (ft_vec3_dot_product(*cy.n, *r->d) > 0)//inside
				*color = 0x0000ff;
		}
		free(cp);
		free(tmp);
	}
	free(ec);
}

void	ft_cylinder_touch(t_ray *r, t_pixel_unit *u)
{
	t_cylinder	cy;

	ft_make_cylinder(&cy);
	ft_cylinder_touch_side(r, cy, u);
	ft_cylinder_touch_circle(r, cy, u);
}
