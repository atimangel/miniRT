#include "minirt.h"

void	ft_diffuse_reflection(t_ray *r, t_pixel_unit *u, t_light light)
{
	t_vec3	*point;
	t_vec3	*tmp;
	t_vec3	*lp;
	double	cos;
	t_vec3	ratio;
	double	distance;

	tmp = ft_vec3_scale(*r->d, r->t);
	point = ft_vec3_add(*r->e, *tmp);
	free(tmp);
	lp = ft_vec3_remove(*light.c, *point);
	cos = ft_vec3_dot_product(*lp, *u->o_n) / ft_vec3_len(*lp) / ft_vec3_len(*u->o_n);
	distance = ft_vec3_len(*lp);
	if (cos > 0)
	{
		u->p_r = u->o_r * light.red * cos * light.ratio / 255 / (1 + 0.1 * distance + 0.01 * pow(distance, 2.0));
		u->p_g = u->o_g * light.green * cos * light.ratio / 255 / (1 + 0.1 * distance + 0.01 * pow(distance, 2.0));
		u->p_b = u->o_b * light.blue * cos * light.ratio / 255 / (1 + 0.1 * distance + 0.01 * pow(distance, 2.0));
	}
	free(point);
	free(lp);
}
