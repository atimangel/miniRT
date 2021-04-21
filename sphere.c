#include "minirt.h"
#include <stdio.h>

typedef struct s_sphere
{
	t_vec3	*center;
	double	r;
	int	color;
}		t_sphere;

void	ft_sphere_touch(t_ray *r, int *color)
{
	t_sphere s;
	double	a;
	double	b;
	double	c;
	double	t;
	t_vec3	*tmp;

	t = -1.0;
	s.center = ft_vec3(0.0, 0.0, -5.0);
	s.r = 1.0;
	s.color = 0x01d030;
	a = ft_vec3_dot_product(*r->d, *r->d);
	tmp = ft_vec3_remove(*r->e, *s.center);
	c = ft_vec3_dot_product(*tmp, *tmp) - pow(s.r, 2.0);
	b = ft_vec3_dot_product(*r->d, *tmp) * 2;
	free(tmp);
	free(s.center);
	if (pow(b, 2.0) - 4 * a * c < 0)
		t = -1;
	if ((t = (-b - sqrt(pow(b, 2.0) - 4 * a * c)) / 2 * a) > 0 && ((r->t > 0 && t < r->t)|| r->t <= 0))
	{
		r->t = t;
		printf("per %f\n", (r->t_max - r->t) / r->t_max);
		*color = 0x90 * (r->t_max - r->t) / r->t_max;
	}
	else if ((t = (- b + sqrt(pow(b, 2.0) - 4 * a * c)) / 2 * a) > 0 && r->t > 0 && t < r->t)
	{
		r->t = t;
		*color = 0x000090 * (r->t_max - r->t) / r->t_max;
	}
}
