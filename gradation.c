#include <mlx.h>
#include <stdio.h>

int		color_map(void *mlx, void *win, int w, int h)
{
	int x;
	int y;
	int color;

	x = w;
	while (x--)
	{
		color = (x * 0xff / w) << 16;
		y = h;
		while (y--)
			mlx_pixel_put(mlx, win, x, y, color);
	}
	return (0);
}

int		color_map_blue(void *mlx, void *win, int w, int h)
{
	int x;
	int y;
	int color;

	x = w;
	while (x--)
	{
		color = ((w - x) * 0xff / w);
		y = h;
		while (y--)
			mlx_pixel_put(mlx, win, x, y, color);
	}
	return (0);
}

int		color_map_green(void *mlx, void *win, int w, int h)
{
	int x;
	int y;
	int color;

	x = w;
	while (x--)
	{
		y = h;
		while (y--)
		{
			color = ((y * 0xff / h) << 8);
			mlx_pixel_put(mlx, win, x, y, color);
		}
	}
	return (0);
}
int	main(void)
{
	void	*connect;
	void	*window;
	void	*win_2;
	void	*win_3;

	connect = mlx_init();
	window = mlx_new_window(connect, 500, 500, "Red faid out");
	color_map(connect, window, 500, 500);
	win_2 = mlx_new_window(connect, 500, 500, "Blue faid out");
	color_map_blue(connect, win_2, 500, 500);
	win_3 = mlx_new_window(connect, 500, 500, "Green faid out");
	color_map_green(connect, win_3, 500, 500);
	mlx_loop(connect);
}
