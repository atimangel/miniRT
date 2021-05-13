#include "minirt.h"

void	ft_specular_reflection(t_ray r, t_ray trace, t_pixel_unit *u, t_light light)
{
	t_vec3	*reflected_ray;
	t_vec3	*up;
	double	cos;
	double	distance;

	up = ft_vec3_scale(*u->o_n, ft_vec3_dot_product(*trace.d, *u->o_n) * -2 * trace.t);
	reflected_ray = ft_vec3_add(*trace.d, *up);
	cos = ft_vec3_dot_product(*reflected_ray, *r.d) / ft_vec3_len(*r.d) / ft_vec3_len(*reflected_ray) * -1;
	cos = pow(cos, 32);
	distance = trace.t;
	if (cos > 0)
	{
		u->p_r += light.red * cos / (1 + 0.000001 * distance + 0.0000000001 * distance);
		u->p_g += light.green * cos / (1 + 0.000001 * distance + 0.0000000001 * distance);
		u->p_b += light.blue * cos / (1 + 0.000001 * distance + 0.0000000001 * distance);
	}
	free(reflected_ray);
	free(up);
}
