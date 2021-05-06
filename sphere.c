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

t_vec3	*ft_sphere_normal(t_sphere s, t_ray *r, double t)
{
	t_vec3	*normal;
	t_vec3	*p;
	t_vec3	*tmp;
	t_vec3	*aaa;

/*	tmp = ft_vec3_scale(*r->d, t);
	p = ft_vec3_add(*r->e, *tmp);
	normal = ft_vec3_remove(*p, *s.center);
	free(p);
	free(tmp);*/
	return (normal);
}

void	ft_sphere_touch(t_ray *r, t_pixel_unit *u)
{
	t_sphere s;
	double	a;
	double	b;
	double	c;
	double	t;
	t_vec3	*tmp;

/*	t = -1.0;
//	ft_make_sphere(&s);
	a = ft_vec3_dot_product(*r->d, *r->d);
	tmp = ft_vec3_remove(*r->e, *s.center);
	c = ft_vec3_dot_product(*tmp, *tmp) - pow(s.radius, 2.0);
	b = ft_vec3_dot_product(*r->d, *tmp) * 2;
	free(tmp);
	if (pow(b, 2.0) - 4 * a * c < 0)
		t = -1;
	if ((t = (-b - sqrt(pow(b, 2.0) - 4 * a * c)) / (2 * a)) > 0 && ((r->t > 0 && t < r->t)|| r->t <= 0))
	{
		r->t = t;
		u->o_r = s.red;
		u->o_g = s.green;
		u->o_b = s.blue;
		if (u->o_n != 0)
			free(u->o_n);
		u->o_n = ft_sphere_normal(s, r, t);
	}
	else if ((t = (- b + sqrt(pow(b, 2.0) - 4 * a * c)) / 2 * a) > 0 && r->t > 0 && t < r->t)
	{
		r->t = t;
		u->o_r = s.red;
		u->o_g = s.green;
		u->o_b = s.blue;
		if (u->o_n != 0)
			free(u->o_n);
		tmp = ft_sphere_normal(s, r, t);
		u->o_n = ft_vec3_scale(*tmp, -1.0);
	}
	free(s.center);*/
}
