#include "libft_bonus.h"

t_vec3		*ft_vec3_add(t_vec3 v1, t_vec3 v2)
{
	int i;
	t_vec3 *added;

	added = (t_vec3 *)malloc(sizeof(t_vec3));
	if (!added)
		return (0);
	i = 0;
	while (i < 4)
	{
		(*added)[i] = v1[i] + v2[i];
		i++;
	}
	return (added);
}
