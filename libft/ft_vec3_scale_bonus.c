#include "libft_bonus.h"

t_vec3		ft_vec3_scale(t_vec3 v, double scala)
{
	t_vec3	*scaled;
	int		i;

	scaled = (t_vec3 *)malloc(sizeof(t_vec3));
	i = 0;
	while (i < 3)
	{
		scaled[i] = v[i] * scala;
		i++;
	}
	scaled[i] = 1.0;
	return (scaled);
}
