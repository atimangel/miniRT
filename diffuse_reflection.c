#include "minirt.h"

void	ft_diffuse_reflection(t_ray trace, t_pixel_unit *u, t_light light)
{
	t_vec3	*lp;
	double	cos;
	double	distance;

	lp = ft_vec3_remove(trace.e, *trace.d);
	cos = ft_vec3_dot_product(*lp, *u->o_n) / ft_vec3_len(*lp) / ft_vec3_len(*u->o_n);
	distance = ft_vec3_len(*lp);
	if (cos > 0)
	{
		u->p_r += u->o_r * light.red * cos * light.ratio / 255 / (1 + 0.0001 * distance + 0.000001 * pow(distance, 2.0));
		u->p_g += u->o_g * light.green * cos * light.ratio / 255 / (1 + 0.0001 * distance + 0.000001 * pow(distance, 2.0));
		u->p_b += u->o_b * light.blue * cos * light.ratio / 255 / (1 + 0.0001 * distance + 0.000001 * pow(distance, 2.0));
	}
	free(lp);
}
