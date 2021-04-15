//#include "libft_bonus.h"
#include "minirt.h"

/*typedef struct s_mlx
{
	void	*ptr;
	void	*win;
}		t_mlx;*/
/*
void	ft_make_window(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, 500, 500, "miniRT by snpark");
}*/
/*
int	ft_exit_event(int a, void *parm)
{
	exit(0);
	return (0);
}

int	ft_key_press(int key, void *parm)
{
	printf("press %d\n", key);
	if (key == 53)
		exit(0);
	return (0);
}

void	ft_hook_event(t_mlx mlx)
{
	mlx_key_hook(mlx.win, ft_key_press, 0);
	mlx_hook(mlx.win, 17, 0, ft_exit_event, 0);
}*/

int	main(void)
{
	t_mlx	mlx;
	
	ft_make_window(&mlx);
	ft_hook_event(mlx);
	mlx_loop(mlx.ptr);
}
