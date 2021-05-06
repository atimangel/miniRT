#include "minirt.h"

void	ft_make_window(t_mlx *mlx, t_list *obj)
{
	t_resolution 	*res;

	res = ft_find_obj(obj, R, 0);
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, res->x, res->y, "miniRT by snpark");
}
