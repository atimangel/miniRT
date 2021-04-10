#include <mlx.h>
#include <stdlib.h>
typedef struct s_data {
	void	*connect;
	void	*window;
}				t_data;

int	press_esc(int key, void *data)
{
	if (key == 53)
		exit(0);
	return (0);
}

int		main(void)
{
	t_data data;

	data.connect = mlx_init();
	data.window = mlx_new_window(data.connect, 500, 500, "esc is escape!");
	mlx_key_hook(data.window, press_esc, &data);
	mlx_loop(data.connect);
}
