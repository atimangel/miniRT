#include "minirt.h"

typedef struct s_image_plane
{
	int tmp_c;
}		t_image_plane;

void	ft_trans_image_plane(t_pixel_unit u, t_image_plane ip)
{
	t_vec3 a;
	t_vec3 b;
	t_vec3 c;

	a.v[0] = 0;
	a.v[1] = 2;
	a.v[2] = 3;
	a.v[3] = 5;
	b.v[0] = 2;
	b.v[1] = 6;
	b.v[2] = 2;
	b.v[3] = 8;
	ft_vec3_add(a, b, c);
	printf("%f\n", c.v[1]);
}

void	ft_make_pixel_map(t_mlx mlx, t_pixel_map *pm)
{
	pm->img_ptr = mlx_new_image(mlx.ptr, 500, 500);
	pm->pixel_str = mlx_get_data_addr(pm->img_ptr, &pm->bpp, &pm->l_len, &pm->endian);
}

void	ft_draw_pixel_map(t_mlx mlx, t_pixel_map pm)
{
	t_pixel_unit u;
	t_image_plane ip;

	u.x = 0;
	u.color = 0xf9f9ff;
	while (u.x < 500)
	{
		u.y = 0;
		while (u.y < 500)
		{
			ft_trans_image_plane(u, ip);
			*(unsigned int *)(pm.pixel_str + pm.l_len * u.y + pm.bpp * u.x / 8) = u.color;
			u.y++;
		}
		u.x++;
	}
	mlx_put_image_to_window(mlx.ptr, mlx.win, pm.img_ptr, 0, 0);
}
