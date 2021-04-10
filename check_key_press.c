#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_data {
	void	*connect;
	void	*window;
}				t_data;

int	print_press_key(int key, void *data)
{
	printf("you press %dkey\n", key);
	if (key == 53)
		exit(0);
	return (0);
}

int		main(void)
{
	t_data data;

	data.connect = mlx_init();
	data.window = mlx_new_window(data.connect, 500, 500, "Let's ckeck keycode!!");
	mlx_key_hook(data.window, print_press_key, &data);
	mlx_loop(data.connect);
}
