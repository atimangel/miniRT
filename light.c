#include "minirt.h"

void	ft_make_light(t_light *light)
{
	light->c = ft_vec3(0.0, 0.0, 0.0);
	light->ratio = 0.8;
	light->red = 255;
	light->green = 255;
	light->blue = 255;
}

void	ft_light_max(t_pixel_unit *u)
{
	if (u->p_r > 255)
		u->p_r = 255;
	if (u->p_g > 255)
		u->p_g = 255;
	if (u->p_b > 255)
		u->p_b = 255;
}
