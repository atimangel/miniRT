#include "minirt.h"

void	ft_diffuse_reflection(t_ray *r, t_pixel_unit *u, t_light light)
{
	t_vec3	*point;
	t_vec3	*tmp;
	t_vec3	*lp;
	double	cos;
	t_vec3	ratio;

	tmp = ft_vec3_scale(*r->d, r->t);
	point = ft_vec3_add(*r->e, *tmp);
	free(tmp);
	lp = ft_vec3_remove(*light.c, *point);
	cos = ft_vec3_dot_product(*lp, *u->o_n) / ft_vec3_len(*lp) / ft_vec3_len(*u->o_n);
	ft_putvec(*lp);
	ft_putvec(*u->o_n);
	printf("cos %f\n", cos);
	if (cos > 0)
	{
		ratio[0] = light.red * cos * light.ratio / 255;
		ratio[1] = light.green * cos * light.ratio / 255;
		ratio[2] = light.blue * cos * light.ratio / 255;
		u->p_r += u->o_r * ratio[0];
		u->p_g += u->o_g * ratio[1];
		u->p_b += u->o_b * ratio[2];
	}
	free(point);
	free(lp);
}
