#include "minirt.h"

void	ft_make_window(t_mlx *mlx, t_resolution res)
{
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, res.x, res.y, "miniRT by snpark");
}
