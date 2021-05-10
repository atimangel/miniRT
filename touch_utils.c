#include "minirt.h"

char	ft_isclose(double origin, double new)
{
	return (((origin > 0 && new < origin) || origin <= 0) && new > 0);
}

void	ft_putcolor(t_pixel_unit *u, unsigned char red, unsigned char green, unsigned char blue)
{
	u->o_r = red;
	u->o_g = green;
	u->o_b = blue;
}
