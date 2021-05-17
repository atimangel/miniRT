#include "mlx.h"

int	main(void)
{
	void *ptr;
	void *win;

	ptr = mlx_init();
	win = mlx_new_window(ptr, 500, 500, "destoy window");
	mlx_loop(ptr);
}
