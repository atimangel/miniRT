#include "minirt.h"

void	ft_make_light(t_light *light)
{
	light->c = ft_vec3(0.0, 0.0, 0.0);
	light->ratio = 0.6;
	light->red = 255;
	light->green = 255;
	light->blue = 255;
}
