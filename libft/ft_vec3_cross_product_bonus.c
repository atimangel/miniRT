#include "libft_bonus.h"

t_vec3		ft_vec3_cross_product(t_vec3 v1, t_vec3 v2)
{
	t_vec3	cross;
	int		i;

	i = 0;
	while (i < 3)
	{
		cross.v[i] += v1.v[(i + 1) % 3] * v2.v[(i + 2) % 3];
		cross.v[i] -= v1.v[(i + 2) % 3] * v2.v[(i + 1) % 3];
		i++;
	}
	return (cross);
}
