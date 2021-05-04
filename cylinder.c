#include "minirt.h"

void	*ft_make_cylinder(char *line)
{
	t_cylinder	*c;
	t_vec3		*tmp;
	t_vec3		*tmp2;

	c = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!c)
		printf("error\nmalloc error cylinder\n");
	line += 2;
	c->id = cy;
	line = ft_pass_space(line);
	line = ft_read_vec3(line, c->center);
	line = ft_pass_space(line);
	line = ft_read_vec3(line, c->normal);
	line = ft_pass_space(line);
	line = ft_read_float(line, &c->diameter, 0);
	line = ft_pass_space(line);
	line = ft_read_float(line, &c->height, 0);
	line = ft_pass_space(line);
	line = ft_read_char(line, &c->red, 1);
	line = ft_read_char(line, &c->green, 1);
	line = ft_read_char(line, &c->blue, 0);
	line = ft_pass_space(line);
	if (*line != '\0')
		printf("error\nstring is not end nullcharacter cylinder.c\n");
	if (ft_vec3_len(c->normal) != 1.0)
	{
		tmp = ft_vec3_normalize(c->normal);
		ft_memcpy(&c->normal, tmp, sizeof(t_vec3));
		free(tmp);
	}
	if (c->diameter <= 0)
		printf("error\ncylinder's diameter is equl less than zero\n");
	tmp = ft_vec3_scale(c->normal, c->height);
	tmp2 = ft_vec3_add(c->center, *tmp);
	ft_memcpy(&c->center2, tmp2, sizeof(t_vec3));
	free(tmp);
	free(tmp2);
	return (c);
}

t_vec3	*ft_cylinder_side_normal(t_ray r, t_cylinder cy, double t, double alpha)
{
/*	t_vec3	*iormal;
	t_vec3	*center;
	t_vec3	*point;
	t_vec3	*tmp;

	tmp = ft_vec3_scale(*cy.n, alpha);
	center = ft_vec3_add(*cy.c, *tmp);
	free(tmp);
	tmp = ft_vec3_scale(*r.d, t);
	point = ft_vec3_add(*r.e, *tmp);
	free(tmp);
	normal = ft_vec3_remove(*point, *center);
	return (normal);*/
	return (0);
}

void	ft_cylinder_touch_side(t_ray *r, t_cylinder cy, t_pixel_unit *u)
{
/*	double	a;
	double	b;
	double	c;
	double	t;
	double	alpha;
	t_vec3	*ce;
	t_vec3	*tmp;

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
				u->o_n = ft_cylinder_side_normal(*r, cy, t, alpha);
			}
		}
		if ((t = (-b - sqrt(pow(b, 2.0) - a * c)) / a) > 0 &&
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
				tmp = ft_cylinder_side_normal(*r, cy, t, alpha);
				u->o_n = ft_vec3_scale(*tmp, -1);
				free(tmp);
			}
		}
	}
	free(ce);*/
}

void	ft_cylinder_touch_circle(t_ray *r, t_cylinder cy, t_pixel_unit *u)
{
/*	t_vec3	*tmp;
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
			{
				u->o_r = cy.red;
				u->o_g = cy.green;
				u->o_b = cy.blue;
				if (u->o_n != 0)
					free(u->o_n);
				u->o_n = ft_vec3_scale(*cy.n, -1);
			}
			else if (ft_vec3_dot_product(*cy.n, *r->d) < 0)//inside
			{
				u->o_r = cy.red;
				u->o_g = cy.green;
				u->o_b = cy.blue;
				if (u->o_n != 0)
					free(u->o_n);
				u->o_n = cy.n;
			}
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
		if (radius >= -cy.r && radius <= cy.r)
		{
			r->t = t;
			if (ft_vec3_dot_product(*cy.n, *r->d) < 0)//outside
			{
				u->o_r = cy.red;
				u->o_g = cy.green;
				u->o_b = cy.blue;
				if (u->o_n != 0)
					free(u->o_n);
				u->o_n = cy.n;
			}
			else if (ft_vec3_dot_product(*cy.n, *r->d) > 0)//inside
			{
				u->o_r = cy.red;
				u->o_g = cy.green;
				u->o_b = cy.blue;
				if (u->o_n != 0)
					free(u->o_n);
				u->o_n = ft_vec3_scale(*cy.n, -1);
			}
		}
		free(cp);
		free(tmp);
	}
	free(ec);*/
}

void	ft_cylinder_touch(t_ray *r, t_pixel_unit *u)
{
/*	t_cylinder	cy;

	ft_make_cylinder(&cy);
	ft_cylinder_touch_side(r, cy, u);
	ft_cylinder_touch_circle(r, cy, u);
	if (u->o_n != cy.n)
		free(cy.n);
	free(cy.c);*/
}
