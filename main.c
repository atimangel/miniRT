//#include "libft_bonus.h"
//#include "minirt.h"
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
}		t_mlx;

void	ft_make_window(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, 500, 500, "miniRT by snpark");
}

int	ft_exit_event(int a, void *parm)
{
	exit(0);
	return (0);
}

int	ft_key_press(int key, void *parm)
{
	if (key == 53)
	{
		exit(0);
	}
	return (0);
}
void	ft_hook_event(t_mlx *mlx)
{
	mlx_key_hook(mlx->ptr, ft_key_press, mlx);

/*	mlx_hook(mlx->ptr, 2, 0, key_press_hook, 0);
	mlx_hook(mlx->ptr, 3, 0, key_release, 0);
	mlx_hook(mlx->ptr, 4, 0, mouse_press, 0);
	mlx_hook(mlx->ptr, 5, 0, mouse_release, 0);
	mlx_hook(mlx->ptr, 6, 0, motion, 0);
	mlx_hook(mlx->ptr, 12, 0, expose, 0);*/
	//mlx_hook(mlx->ptr, 17, 0, ft_exit_event, 0);
	mlx_loop(mlx->ptr);
}

int	main(void)
{
	t_mlx	mlx;
	
	ft_make_window(&mlx);
//	ft_hook_event(mlx);
	mlx_loop(mlx.ptr);
}
