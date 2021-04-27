#include "minirt.h"
#include <stdio.h>

typedef struct s_sphere
{
	t_vec3	*center;
	double	radius;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}		t_sphere;

void	ft_make_sphere(t_sphere *s)
{
	s->center  = ft_vec3(0.0, 0.0, -5.0);
	s->radius = 1.0;
	s->red = 0x0;
	s->green = 0xff;
	s->blue = 0xff;
}

t_vec3	*ft_sphere_normal(t_vec3 *c, t_ray *r, double t)
{
	t_vec3	*normal;
	t_vec3	*p;
	t_vec3	*tmp;
	t_vec3	*aaa;

	tmp = ft_vec3_scale(*r->d, t);
	p = ft_vec3_add(*r->e, *tmp);
	normal = ft_vec3_remove(*p, *c);
	aaa = ft_vec3_add(*p, *c);
	printf("aaa");
	ft_putvec(*aaa);
	printf("normal");
	ft_putvec(*normal);
	free(p);
	free(tmp);
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

	t = -1.0;
	ft_make_sphere(&s);
	a = ft_vec3_dot_product(*r->d, *r->d);
	tmp = ft_vec3_remove(*r->e, *s.center);
	c = ft_vec3_dot_product(*tmp, *tmp) - pow(s.radius, 2.0);
	b = ft_vec3_dot_product(*r->d, *tmp) * 2;
	free(tmp);
	free(s.center);
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
		printf("t %f\n", t);
		u->o_n = ft_sphere_normal(s.center, r, t);
		ft_putvec(*u->o_n);
	}
	else if ((t = (- b + sqrt(pow(b, 2.0) - 4 * a * c)) / 2 * a) > 0 && r->t > 0 && t < r->t)
	{
		r->t = t;
		u->o_r = s.red;
		u->o_g = s.green;
		u->o_b = s.blue;
		if (u->o_n != 0)
			free(u->o_n);
		tmp = ft_sphere_normal(s.center, r, t);
		u->o_n = ft_vec3_scale(*tmp, -1.0);
	}
}
