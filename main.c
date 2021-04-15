//#include "libft_bonus.h"
//#include "minirt.h"
#include "mlx.h"
#include <stdlib.h>

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
}		t_mlx;

void	ft_make_window(t_mlx *mlx)
{
	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, 500, 500, "miniRT by snpark");
}

int	main(void)
{
	t_mlx	*mlx;

	ft_make_window(mlx);
	free(mlx);
}
