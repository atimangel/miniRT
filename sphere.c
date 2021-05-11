#include "minirt.h"

void	*ft_make_sphere(char *line)
{
	t_sphere *sp;

	sp = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sp)
		printf("error\nmalloc error sphere.c\n");
	line += 2;
	line = ft_pass_space(line);
	line = ft_read_vec3(line, sp->center);
	line = ft_pass_space(line);
	line = ft_read_float(line, &sp->diameter, 0);
	line = ft_pass_space(line);
	line = ft_read_char(line, &sp->red, 1);
	line = ft_read_char(line, &sp->green, 1);
	line = ft_read_char(line, &sp->blue, 0);
	line = ft_pass_space(line);
	if (*line != '\0')
		printf("error\nstring is not end null character sphere.c");
	if (sp->diameter <= 0.0)
		printf("error\nspher's diameter is same or under zero\n");
	return (sp);
}

t_vec3	*ft_sphere_normal(t_sphere *sp, t_ray *r, double t)
{
	t_vec3	*normal;
	t_vec3	*p;
	t_vec3	*tmp;
	double	dot;

	tmp = ft_vec3_scale(*r->d, t);
	p = ft_vec3_add(r->e, *tmp);
	free (tmp);
	tmp = ft_vec3_remove(*p, sp->center);
	normal = ft_vec3_normalize(*tmp);
	free(p);
	free(tmp);
	if ((dot = ft_vec3_dot_product(*normal, *r->d)) < 0)
		return (normal);
	else if (dot > 0)
	{
		tmp = normal;
		normal = ft_vec3_scale(*tmp, -1.0);
		free(tmp);
	}
	return (normal);
}

void	ft_sphere_touch(t_ray *r, t_pixel_unit *u, void *obj, char flag)
{
	t_sphere *sp;
	double	a;
	double	b;
	double	c;
	double	t;
	t_vec3	*tmp;

	sp = obj;
	t = -1.0;
	a = ft_vec3_dot_product(*r->d, *r->d);
	tmp = ft_vec3_remove(r->e, sp->center);
	b = ft_vec3_dot_product(*r->d, *tmp) * 2;
	c = ft_vec3_dot_product(*tmp, *tmp) - pow(sp->diameter, 2.0);
	free(tmp);
	if (pow(b, 2.0) - 4 * a * c < 0)
		return;
	if ((t = (-b - sqrt(pow(b, 2.0) - 4 * a * c)) / (2 * a)) > 0 && ft_isclose(r->t, t) && flag == 0)
	{
		r->t = t;
		ft_putcolor(u, sp->red, sp->green, sp->blue);
		if (u->o_n != 0)
			free(u->o_n);
		u->o_n = ft_sphere_normal(sp, r, t);
	}
	if ((t = (-b - sqrt(pow(b, 2.0) - 4 * a * c)) / (2 * a)) > 0 && ft_isclose(r->t, t) && flag == 1)
		r->t = t;
	if ((t = (- b + sqrt(pow(b, 2.0) - 4 * a * c)) / (2 * a)) > 0 && ft_isclose(r->t, t) && flag == 0)
	{
		r->t = t;
		ft_putcolor(u, sp->red, sp->green, sp->blue);
		if (u->o_n != 0)
			free(u->o_n);
		u->o_n = ft_sphere_normal(sp, r, t);
	}
	if ((t = (- b + sqrt(pow(b, 2.0) - 4 * a * c)) / (2 * a)) > 0 && ft_isclose(r->t, t) && flag == 1)
		r->t = t;
}
