#include "libft_bonus.h"
#include "libft.h"

t_vec3	*ft_vec3_transform_normal(t_a16 matrix, t_vec3 src)
{
	t_vec3	*dest;
	int	i;
	int	j;

	src[3] = 0.0;
	dest = (t_vec3 *)malloc(sizeof(t_vec3));
	if (!dest)
		return (0);
	ft_bzero(dest, sizeof(t_vec3));
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			(*dest)[i] += matrix[i][j] * src[j];
			j++;
		}
		i++;
	}
	return (dest);
}
