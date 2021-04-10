#include "libft_bonus.h"

t_vec3		ft_vec3_scale(t_vec3 v, double scala)
{
	t_vec3	scaled;
	int		i;

	i = 0;
	while (i < 3)
	{
		scaled.v[i] = v.v[i] * scala;
		i++;
	}
	scaled.v[i] = 1.0;
	return (scaled);
}
