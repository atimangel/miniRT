#include "libft_bonus.h"
#include "libft.h"

t_a16	*ft_matrix(t_vec3 v1, t_vec3 v2, t_vec3 v3)
{
	t_a16	*dest;
	int	i;
	int	j;

	dest = (t_a16 *)malloc(sizeof(t_a16));
	if (!dest)
		return (0);
	ft_memcpy((*dest)[0], v1, sizeof(double) * 3);
	ft_memcpy((*dest)[1], v2, sizeof(double) * 3);
	ft_memcpy((*dest)[2], v3, sizeof(double) * 3);
	i = 0;
	while(i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i == 3 || j == 3)
				(*dest)[i][j] = 0.0;
			if (i == 3 && j == 3)
				(*dest)[i][j] = 1.0;
			j++;
		}
		i++;
	}
	return (dest);
}
