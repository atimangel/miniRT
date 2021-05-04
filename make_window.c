#include "minirt.h"

void	ft_make_window(t_mlx *mlx, t_list *obj)
{
	t_resolution 	*res;

	while (((t_resolution *)obj->content)->id != R)
		obj = obj->next;
	if (!obj)
		printf("error\n where is resolution value?");
	else
	{
		res = obj->content;
		mlx->ptr = mlx_init();
		mlx->win = mlx_new_window(mlx->ptr, res->x, res->y, "miniRT by snpark");
		ft_lstdelone(obj, free);
	}
}
