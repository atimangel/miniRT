#include "minirt.h"

int	main(int arg_c, char **arg_v)
{
	t_mlx	mlx;
	t_pixel_map	pm;
	void	*object;
	
	if (arg_c >= 2 && ft_strnstr(arg_v[1], ".rt", ft_strlen(arg_v[1])) == arg_v[1] + ft_strlen(arg_v[1]) - 3)
		ft_parse_rt(arg_v[1], &object);
	//if (arg_c >= 3 && ft_strncmp(arg_v[2], "-save", 5))
		//ft_save_bmp();
/*	ft_make_window(&mlx);
	ft_make_pixel_map(mlx, &pm);
	ft_draw_pixel_map(mlx, pm);
	ft_hook_event(mlx);
	mlx_loop(mlx.ptr);*/
}
