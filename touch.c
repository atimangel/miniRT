#include "minirt.h"

void	ft_touch(t_ray *r, t_pixel_unit *u, t_list *obj, char flag)
{
	while (obj)
	{
		if (obj->id == sp)
			ft_sphere_touch(r, u, obj->content, flag);
		if (obj->id == pl)
			ft_plane_touch(r, u, obj->content, flag);
		if (obj->id == sq)
			ft_square_touch(r, u, obj->content, flag);
		if (obj->id == cy)
			ft_cylinder_touch(r, u, obj->content, flag);
		if (obj->id == tr)
			ft_triangle_touch(r, u, obj->content, flag);
		obj = obj->next;
	}
}
