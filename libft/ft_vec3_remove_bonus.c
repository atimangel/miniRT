#include "libft_bonus.h"

t_vec3		ft_vec3_remove(t_vec3 v1, t_vec3 v2)
{
	t_vec3		removed;
	int			i;

	i = 0;
	while (i < 3)
	{
		removed.v[i] = v1.v[i] - v2.v[i];
		i++;
	}
	removed.v[i] = 1.0;
	return (removed);
}
