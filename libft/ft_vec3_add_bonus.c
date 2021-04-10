#include "libft_bonus.h"

t_vec3		ft_vec3_add(t_vec3 v1, t_vec3 v2)
{
	int i;
	t_vec3 added;

	i = 0;
	while (i < 4)
	{
		added.v[i] = v1.v[i] + v2.v[i];
		i++;
	}
	return (added);
}
