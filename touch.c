#include "minirt.h"

void	*ft_touch(t_ray *r, t_pixel_unit *u, t_list *obj, char flag)
{
	void	*touched;
	double	t;

	touched = 0;
	t = -1.0;
	while (obj)
	{
		if (obj->id == sp)
			ft_sphere_touch(r, u, obj->content, flag);
		if (obj->id == pl)
			ft_plane_touch(r, u, obj->content, flag);
		if (obj->id == cy)
			ft_cylinder_touch(r, u, obj->content, flag);
		if (r->t != -1.0 && r->t != t)
		{
			touched = obj;
			t = r->t;
		}
		obj = obj->next;
	}
	return (touched);
}
