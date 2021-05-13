#include "minirt.h"

static int	ft_exit_event(int a, void *parm)
{
	void	*ptr;
	void	*win;
	t_list	**obj;

	ptr = ((t_free *)parm)->mlx.ptr;
	win = ((t_free *)parm)->mlx.win;
	obj = ((t_free *)parm)->obj;
	mlx_destroy_window(ptr, win);
	mlx_destroy_display(ptr);
	free(ptr);
	ft_lstclear(obj, free); 
	exit(0);
	return (0);
}

static int	ft_key_press(int key, void *parm)
{
	void	*ptr;
	void	*win;
	t_list	**obj;

	ptr = ((t_free *)parm)->mlx.ptr;
	win = ((t_free *)parm)->mlx.win;
	obj = ((t_free *)parm)->obj;
	printf("press %d\n", key);
	if (key == 53 || key == 65307)
	{
		mlx_destroy_window(ptr, win);
		mlx_destroy_display(ptr);
		free(ptr);
		ft_lstclear(obj, free); 
		exit(0);
	}
	return (0);
}

void		ft_hook_event(t_free *parm)
{
	mlx_key_hook(parm->mlx.win, ft_key_press, parm);
	mlx_hook(parm->mlx.win, 17, 0, ft_exit_event, parm);
}
