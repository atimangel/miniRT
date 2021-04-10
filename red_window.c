#include <mlx.h>

int		main(void)
{
	void	*connect;
	void	*window;
	int		i;
	int		j;

	connect = mlx_init();
	window = mlx_new_window(connect, 500, 500, "earth is flat and red");
	i = 0;
	while (i < 500)
	{
		j = 0;
		while (j < 500)
		{
			mlx_pixel_put(connect, window, i, j, 0x00ff0000);
			j++;
		}
		i++;
	}
	mlx_loop(connect);
}
