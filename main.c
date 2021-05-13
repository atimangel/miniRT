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
	
	if (arg_c >= 2 && ft_strnstr(arg_v[1], ".rt", ft_strlen(arg_v[1])) == arg_v[1] + ft_strlen(arg_v[1]) - 3)
		obj = ft_parse_rt(arg_v[1]);
	else
	{
		printf("error\n no *.rt file\n");
		return (0);
	}
	/*ft_make_window(&mlx, obj);
	ft_make_pixel_map(mlx, &pm, obj);
	ft_draw_pixel_map(pm, obj, *(t_resolution *)ft_find_obj(obj, R, 0), *(t_camera *)ft_find_obj(obj, c, 0));
	mlx_put_image_to_window(mlx.ptr, mlx.win, pm.img_ptr, 0, 0);
	//if (arg_c >= 3 && ft_strncmp(arg_v[2], "-save", 5))
		//ft_save_bmp();
	ft_hook_event(mlx, &obj);
	mlx_loop(mlx.ptr);*/
	ft_lstclear(&obj, free);
}
