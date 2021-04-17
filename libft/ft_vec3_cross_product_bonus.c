#include "libft_bonus.h"

t_vec3		*ft_vec3_cross_product(t_vec3 v1, t_vec3 v2)
{
	t_vec3	*cross;
	int		i;

	cross = (t_vec3 *)malloc(sizeof(t_vec3));
	if (!cross)
		return (0);
	i = 0;
	while (i < 3)
	{
		*(cross)[i] += v1[(i + 1) % 3] * v2[(i + 2) % 3];
		*(cross)[i] -= v1[(i + 2) % 3] * v2[(i + 1) % 3];
		i++;
	}
	return (cross);
}
