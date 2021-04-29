#include "minirt.h"

void	ft_specular_reflection(t_ray *r, t_pixel_unit *u, t_light light)
{
	t_vec3	*point;
	t_vec3	*tmp;
	t_vec3	*lp;
	t_vec3	*reflected_ray;
	t_vec3	*up;
	double	cos;
	double	distance;

	tmp = ft_vec3_scale(*r->d, r->t);
	point = ft_vec3_add(*r->e, *tmp);
	free(tmp);

	lp = ft_vec3_remove(*light.c, *point);
	up = ft_vec3_scale(*u->o_n, ft_vec3_dot_product(*lp, *u->o_n) * -1 / ft_vec3_len(*u->o_n) * 2);
	reflected_ray = ft_vec3_add(*lp, *up);

	cos = ft_vec3_dot_product(*reflected_ray, *r->d) / ft_vec3_len(*r->d) / ft_vec3_len(*reflected_ray) * -1;
	cos = pow(cos, 32);
	distance = ft_vec3_len(*lp);
	if (cos > 0)
	{
		u->p_r += light.red * cos / (1 + 0.1 * distance + 0.01 * distance);
		u->p_g += light.green * cos / (1 + 0.1 * distance + 0.01 * distance);
		u->p_b += light.blue * cos / (1 + 0.1 * distance + 0.01 * distance);
	}
	free(lp);
	free(point);
	free(reflected_ray);
	free(up);
}
