#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars {
	void *mlx;
	void *win;
}				t_vars;

int			close(int keycode, t_vars *vars)
{
	printf("keycode = %d\n", keycode);	
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (vars->win == 0)
		exit(0);
	return (0);
}

int			button_close(int button, t_vars *vars)
{
	exit(0);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y* data ->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int		main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		i;
	t_vars vars;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 100, 100, "Hello World!");
	img.img = mlx_new_image(mlx, 100, 100);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	i = 0;
	while (i++ < 100)
	{
		my_mlx_pixel_put(&img, i, 50 - i, 0x00ff0000);
		my_mlx_pixel_put(&img, 50, i, 0x0000ff00);
		my_mlx_pixel_put(&img, i, 50, 0x000000ff);
	}
	vars.mlx = mlx;
	vars.win = mlx_win;
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_key_hook(mlx_win, close, &vars);
	mlx_hook(vars.win, 17, 0, button_close, &vars);
	mlx_loop(mlx);
}
