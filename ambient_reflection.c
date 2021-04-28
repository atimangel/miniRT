#include "minirt.h"

typedef struct s_ambient_ilumination
{
	double		ratio;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}		t_ambient_ilumination;

void	ft_make_ambient_ilumination(t_ambient_ilumination *amb)
{
	amb->ratio = 0.1;
	amb->r = 255;
	amb->g = 255;
	amb->b = 255;
}

void	ft_ambient_reflection(t_pixel_unit *u)
{
	t_ambient_ilumination amb;
	t_vec3			light;

	ft_make_ambient_ilumination(&amb);
	light[0] = amb.ratio * amb.r / 255;
	light[1] = amb.ratio * amb.g / 255;
	light[2] = amb.ratio * amb.b / 255;
	u->p_r = u->o_r * light[0];
	u->p_g = u->o_g * light[1];
	u->p_b = u->o_b * light[2];
}
