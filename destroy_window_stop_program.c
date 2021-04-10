#include <mlx.h>
#include <stdlib.h>

int		destroy_notifyer(int a, void *b)
{
	exit(0);
}

int		main(void)
{
	void	*connect;
	void	*window;

	connect = mlx_init();
	window = mlx_new_window(connect, 500, 500, "earth will stop when you click x-box");
	mlx_hook(window, 17, 0, destroy_notifyer, 0);
	mlx_loop(connect);
}
