#ifndef MINIRT_H
# define MINIRT_H

#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
}		t_mlx;

void	ft_make_window(t_mlx *mlx);
void	ft_hook_event(t_mlx mlx);

#endif
