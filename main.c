//#include "libft_bonus.h"
//#include "minirt.h"
#include "mlx.h"
#include <stdlib.h>

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
}		t_mlx;

void	ft_make_window(void *mlx)
{
	t_mlx *new;

	new = (t_mlx *)malloc(sizeof(t_mlx));
	new->ptr = mlx_init();
	new->win = mlx_new_window(new->ptr, 500, 500, "miniRT by snpark");
	mlx = new;
}

int	main(void)
{
	void	*mlx;

	ft_make_window(mlx);
}
