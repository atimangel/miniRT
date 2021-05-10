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
	t_vec3	*normal;
	t_vec3	*center;
	t_vec3	*point;
	t_vec3	*tmp;

	tmp = ft_vec3_scale(cy.normal, alpha);
	center = ft_vec3_add(cy.center, *tmp);
	free(tmp);
	tmp = ft_vec3_scale(*r.d, t);
	point = ft_vec3_add(r.e, *tmp);
	free(tmp);
	normal = ft_vec3_remove(*point, *center);
	return (normal);
}

double	ft_root_fomula(t_ray *r, t_cylinder cy, t_vec3 *ce, char negative)
{
	double	a;
	double	b;
	double	c;

	a = pow(ft_vec3_dot_product(*r->d, cy.normal), 2) - ft_vec3_dot_product(*r->d, *r->d);
	b = ft_vec3_dot_product(*r->d, cy.normal) * ft_vec3_dot_product(*ce, cy.normal) - ft_vec3_dot_product(*ce, *r->d);
	c = pow(cy.diameter, 2.0) - ft_vec3_dot_product(*ce, *ce) + pow(ft_vec3_dot_product(*ce, cy.normal), 2);
	if (pow(b, 2.0) - a * c < 0)
		return (-1.0);
	return ((-b + negative * sqrt(pow(b, 2.0) - a * c)) /  a);
}

char	ft_isclose(double origin, double new)
{
	return ((origin > 0 && new < origin) || origin <= 0);
}

void	ft_putcolor(t_pixel_unit *u, char red, char green, char blue)
{
	u->o_r = red;
	u->o_g = green;
	u->o_b = blue;
}
double	ft_cylinder_touch_side(t_ray *r, t_cylinder cy, t_pixel_unit *u)
{
	double	t;
	double	alpha;
	t_vec3	*ce;
	t_vec3	*tmp;

	ce = ft_vec3_remove(r->e, cy.center);
	alpha = -1.0;
	if ((t = ft_root_fomula(r, cy, ce, -1)) >= 0 && ft_isclose(r->t, t))
	{
		alpha = ft_vec3_dot_product(*ce, cy.normal) + t * ft_vec3_dot_product(*r->d, cy.normal);
		if (alpha >= 0 && alpha <= cy.height)
		{
			ft_putcolor(u, cy.red, cy.green, cy.blue);
			if (u->o_n != 0)
				free(u->o_n);
			u->o_n = ft_cylinder_side_normal(*r, cy, t, alpha);
		}
	}
	if ((t = ft_root_fomula(r, cy, ce, 1)) >= 0 && ft_isclose(r->t, t))
	{
		alpha = ft_vec3_dot_product(*ce, cy.normal) + t * ft_vec3_dot_product(*r->d, cy.normal);
		if (alpha >= 0 && alpha <= cy.height)
		{
			ft_putcolor(u, cy.red, cy.green, cy.blue);
			if (u->o_n != 0)
				free(u->o_n);
			tmp = ft_cylinder_side_normal(*r, cy, t, alpha);
			u->o_n = ft_vec3_scale(*tmp, -1);
			free(tmp);
		}
	}
	free(ce);
	if (alpha >= 0 && alpha <= cy.height)
		return (t);
	return (-1.0);
}

double	ft_cylinder_touch_circle(t_ray *r, t_cylinder cy, t_pixel_unit *u)
{
	t_vec3	*tmp;
	double	t;
	t_vec3	*ec;
	double	radius;
	t_vec3	*cp;

	ec = ft_vec3_remove(cy.center, r->e);
	if ((t = ft_vec3_dot_product(*ec, cy.normal) / ft_vec3_dot_product(*r->d, cy.normal)) > 0 && ft_isclose(r->t, t))
	{
		tmp = ft_vec3_scale(*r->d, t);
		cp = ft_vec3_remove(*tmp, *ec);
		free(tmp);
		free(cp);
		radius = ft_vec3_len(*cp);
		if (radius >= -cy.diameter && radius <= cy.diameter)
		{
			ft_putcolor(u, cy.red, cy.green, cy.blue);
			if (u->o_n != 0)
				free(u->o_n);
			if (ft_vec3_dot_product(cy.normal, *r->d) > 0)//outside
				u->o_n = ft_vec3_scale(cy.normal, -1);
			else if (ft_vec3_dot_product(cy.normal, *r->d) < 0)//inside
				ft_memcpy(u->o_n, &cy.normal, sizeof(t_vec3));
			free(ec);
			return (t);
		}
	}
	free(ec);
	ec = ft_vec3_remove(cy.center2, r->e);
	if ((t = ft_vec3_dot_product(*ec, cy.normal) / ft_vec3_dot_product(*r->d, cy.normal)) > 0 && ft_isclose(r->t, t))//괄호 때문에 2시간 씀
	{
		tmp = ft_vec3_scale(*r->d, t);
		cp = ft_vec3_remove(*tmp, *ec);
		radius = ft_vec3_len(*cp);
		free(cp);
		free(tmp);
		if (radius >= -cy.diameter && radius <= cy.diameter)
		{
			ft_putcolor(u, cy.red, cy.green, cy.blue);
			if (u->o_n != 0)
				free(u->o_n);
			if (ft_vec3_dot_product(cy.normal, *r->d) < 0)//outside
				ft_memcpy(u->o_n, &cy.normal, sizeof(t_vec3));
			else if (ft_vec3_dot_product(cy.normal, *r->d) > 0)//inside
				u->o_n = ft_vec3_scale(cy.normal, -1);
			free(ec);
			return (t);
		}
	}
	free(ec);
	return (-1.0);
}

double	ft_cylinder_touch(t_ray *r, t_pixel_unit *u, void *obj, char flag)
{
	t_cylinder	*cy;
	double		t1;
	double		t2;

	cy = obj;
	t1 = ft_cylinder_touch_side(r, *cy, u);
	t2 = ft_cylinder_touch_circle(r, *cy, u);
	if (t1 != -1 && t2 == -1)
		return (t1);
	if (t2 != -1)
		return (t2);
	return (-1);
}
