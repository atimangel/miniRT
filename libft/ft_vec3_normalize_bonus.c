#include "libft_bonus.h"

t_vec3		*ft_vec3_normalize(t_vec3 v)
{
	t_vec3	*normalized;
	double	len;
	int		i;

	normalized = (t_vec3 *)malloc(sizeof(t_vec3));
	if (!normalized)
		return (0);
	i = 0;
	len = ft_vec3_len(v);
	while (i < 3)
	{
		normalized[i] = v[i] / len;
		i++;
	}
	normalized[3] = 1;
	return (normalized);
}
