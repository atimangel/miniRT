#include "minirt.h"

static int	ft_exit_event(int a, void *parm)
{
	void	*ptr;
	void	*win;
	void	*img;
	t_list	**obj;

	a = 0;
	ptr = ((t_free *)parm)->ptr;
	win = ((t_free *)parm)->win;
	obj = ((t_free *)parm)->obj;
	img = ((t_free *)parm)->img;
	mlx_destroy_image(ptr, img);
	mlx_destroy_window(ptr, win);
	//mlx_destroy_display(ptr);
	free(ptr);
	ft_lstclear(obj, free); 
	exit(0);
	return (0);
}

static int	ft_key_press(int key, void *parm)
{
	void	*ptr;
	void	*win;
	void	*img;
	t_list	**obj;

	ptr = ((t_free *)parm)->ptr;
	win = ((t_free *)parm)->win;
	obj = ((t_free *)parm)->obj;
	img = ((t_free *)parm)->img;
	printf("press %d\n", key);
	if (key == 53 || key == 65307)
	{
		mlx_destroy_window(ptr, win);
		mlx_destroy_image(ptr, img);
		//mlx_destroy_display(ptr);
		free(ptr);
		ft_lstclear(obj, free); 
		exit(0);
	}
	return (0);
}

void		ft_hook_event(t_free *parm)
{
	mlx_key_hook(parm->win, ft_key_press, parm);
	mlx_hook(parm->win, 17, 0, ft_exit_event, parm);
}
