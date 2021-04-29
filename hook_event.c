#include "minirt.h"

static int	ft_exit_event(int a, void *parm)
{
	exit(0);
	return (0);
}

static int	ft_key_press(int key, void *parm)
{
	printf("press %d\n", key);
	if (key == 53 || key == 65307)
		exit(0);
	return (0);
}

void		ft_hook_event(t_mlx mlx)
{
	mlx_key_hook(mlx.win, ft_key_press, 0);
	mlx_hook(mlx.win, 17, 0, ft_exit_event, 0);
}
