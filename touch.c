#include "minirt.h"

void	ft_touch(t_ray *r, t_pixel_unit *u, t_list *obj)
{
	double	t;

	t = -1.0;
	while (obj)
	{
		if (obj->id == sp)
			t = ft_sphere_touch(r, u, obj->content, 0);
		if (obj->id == pl)
			t = ft_plane_touch(r, u, obj->content, 0);
		if (obj->id == sq)
			t = ft_square_touch(r, u, obj->content, 0);
		if (obj->id == cy)
			t = ft_cylinder_touch(r, u, obj->content, 0);
		if (obj->id == tr)
			t = ft_triangle_touch(r, u, obj->content, 0);
		obj = obj->next;
		if (t != -1.0)
			r->t = t;
	}
}
