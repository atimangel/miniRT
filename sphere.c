#include "minirt.h"

typedef struct s_sphere
{
	t_vec3	*center;
	double	r;
	int	color;
}		t_sphere;

double	ft_sphere_touch(t_ray r)
{
	s_sphere s;
	double	a;
	double	b;
	double	c;
	double	t;
	t_vec3	tmp;

	s.center = ft_vec3(0.0, 0.0, -1.0);
	s.r = 0.1;
	s.color = 0x09d010;
	a = ft_vec3_dot_product(*r.d, *r.d);
	tmp = ft_vec3_remove(*r.e, *s.center);
	c = ft_vec3_dot_product(*tmp, *tmp);
	b = ft_vec3_dot_product(*r.d, *tmp) * 2;
	free(tmp);
	free(s.center);
	if (pow(b) - 4 * a * c < 0)
		return (-1);
	if ((t = (-b - sqrt(pow(b) - 4 * a * c)) / 2 * a) > 0)
		return (t);
	else if (t = (- b + sqrt(pow(b) - 4 * a * c)) / 2 * a) > 0)
		return (t);
	else
		return (-1);
}
