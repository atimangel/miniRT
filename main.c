//#include "libft_bonus.h"
#include "minirt.h"

int	main(void)
{
	t_mlx	mlx;
	t_pixel_map	pm;
	
	ft_make_window(&mlx);
	//ft_parse_rt();
	ft_make_pixel_map(mlx, &pm);
	ft_draw_pixel_map(mlx, pm);
	ft_hook_event(mlx);
	mlx_loop(mlx.ptr);
}
