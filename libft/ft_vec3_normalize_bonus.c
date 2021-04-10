#include "libft_bonus.h"

t_vec3		ft_vec3_normalize(t_vec3 v)
{
	t_vec3	normalized;
	double	len;
	int		i;

	i = 0;
	len = ft_vec3_len(v);
	while (i < 3)
	{
		normalize.v[i] = v.v[i] / len;
		i++;
	}
	normalize.v[3] = 1;
	return (normalized);
}
