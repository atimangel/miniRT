#include <mlx.h>

int	main(void)
{
	void	*connect;
	void	*window;

	connect = mlx_init();
	window = mlx_new_window(connect ,500, 500, "string is print");
	mlx_string_put(connect, window, 400, 400, 0xffffff, "string is printed");
	mlx_loop(connect);
}
