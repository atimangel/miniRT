#include "minirt.h"

typedef struct s_triangle
{
	t_vec3	*o;
	t_vec3	*p1;
	t_vec3	*p2;
	int	color;
}		t_triangle;

void	ft_triangle_touch(t_ray *r, int *color)
{
	double		t;
	t_triangle	tr;

	tr.o = ft_vec3(0.0, 0.0, -7.0);
	tr.p1 = ft_vec3(0.0, 7.0, -7.0);
	tr.p2 = ft_vec3(7.0, 0.0, -7.0);
	tr.color = 0x900000;
	
}
