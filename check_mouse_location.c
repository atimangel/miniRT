#include <mlx.h>
#include <stdio.h>

int		print_mouse_location(int button, int x, int y, void *p)
{
	printf("click(%d,%d)\n", x, y);
	return (0);

}

int		motion_hook(int x, int y, void *p)
{
	printf("move(%d,%d)\n", x, y);
	return (0);
}

int		main(void)
{
	void	*connect;
	void	*window;

	connect = mlx_init();
	window = mlx_new_window(connect, 500, 500, "I know where you are");
	mlx_mouse_hook(window, print_mouse_location, 0);
	mlx_hook(window, 6, 0, motion_hook, 0);
	mlx_loop(connect);
}
