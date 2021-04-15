#include "minirt.h"

void	ft_make_pixel_map(t_mlx mlx, t_pixel_map *pm)
{
	pm->img_ptr = mlx_new_image(mlx.ptr, 500, 500);
	pm->pixel_str = mlx_get_data_addr(pm->img_ptr, &pm->bpp, &pm->l_len, &pm->endian);
}

void	ft_draw_pixel_map(t_mlx mlx, t_pixel_map pm)
{
	t_pixel_unit u;

	u.x = 0;
	u.color = 0xf9f9ff;
	while (u.x < 500)
	{
		u.y = 0;
		while (u.y < 500)
		{
			*(unsigned int *)(pm.pixel_str + pm.l_len * u.y + pm.bpp * u.x / 8) = u.color;
			u.y++;
		}
		u.x++;
	}
	mlx_put_image_to_window(mlx.ptr, mlx.win, pm.img_ptr, 0, 0);
}
