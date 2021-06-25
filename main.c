#include "minirt.h"

void	*ft_find_obj(t_list *obj, enum e_obj id, int order)
{
	if (!obj)
		printf("error\nyou give null pointer to ft_find_obj\n");
	if (order < 0)
		printf("error\nyou try to find %dth %uobj\n", order, id);
	while (obj)
	{
		if (obj->id == id && !order)
			return (obj->content);
		else if (obj->id == id)
			order--;
		obj = obj->next;
	}
	if (!obj)
		printf("error\ncan't find object\n");
	return (0);
}

int	main(int arg_c, char **arg_v)
{
	t_mlx	mlx;
	t_pixel_map	pm;
	t_list		*obj;
	t_image_plane	ip;
	t_free		parm;
	t_resolution	res;

	res.x = 1920;
	res.y = 1080;
	if (arg_c >= 2 && !ft_strncmp(arg_v[1] + ft_strlen(arg_v[1]) - 3, ".rt", 3))
		obj = ft_parse_rt(arg_v[1]);
	else
	{
		printf("error\n no *.rt file\n");
		return (0);
	}
	ft_make_window(&mlx, res);
	ft_make_pixel_map(mlx, &pm, res);
	/*ft_draw_pixel_map(pm, obj, res, *(t_camera *)ft_find_obj(obj, c, 0));
	mlx_put_image_to_window(mlx.ptr, mlx.win, pm.img_ptr, 0, 0);
	parm.win = mlx.win;
	parm.ptr = mlx.ptr;
	parm.img = pm.img_ptr;
	parm.obj = &obj;
	ft_hook_event(&parm);
	mlx_loop(mlx.ptr);*/
	ft_lstclear(&obj, free);
}
