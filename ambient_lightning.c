#include "minirt.h"

typedef struct s_ambient_light
{
	double		ratio;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}		t_ambient_light;

void	ft_make_ambient_light(t_amb_light *amb)
{
	amb->ratio = 0.2;
	amb->r = 255;
	amb->r = 255;
	amb->r = 255;
}

void	ft_render_ambient_light()
{

}
