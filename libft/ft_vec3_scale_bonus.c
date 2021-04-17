#include "libft_bonus.h"

t_vec3		*ft_vec3_scale(t_vec3 v, double scala)
{
	t_vec3	*scaled;
	int		i;

	scaled = (t_vec3 *)malloc(sizeof(t_vec3));
	if (!scaled)
		return (0);
	i = 0;
	while (i < 4)
	{
		(*scaled)[i] = v[i] * scala;
		i++;
	}
	return (scaled);
}
