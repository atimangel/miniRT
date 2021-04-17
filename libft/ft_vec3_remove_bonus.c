#include "libft_bonus.h"

t_vec3		*ft_vec3_remove(t_vec3 v1, t_vec3 v2)
{
	t_vec3		*removed;
	int			i;

	removed = (t_vec3 *)malloc(sizeof(t_vec3));
	if (!removed)
		return (0);
	i = 0;
	while (i < 4)
	{
		(*removed)[i] = v1[i] - v2[i];
		i++;
	}
	return (removed);
}
