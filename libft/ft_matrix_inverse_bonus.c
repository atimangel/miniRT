#include "libft_bonus.h"

t_a16		*ft_matrix_inverse(t_a16 origin, double determinant)
{
	t_a16	*inverse;
	int		i;
	int		j;

	if (determinant == 0.0)
		return (0);
	inverse = (t_a16 *)malloc(sizeof(t_a16));
	if (!inverse)
		return (0);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i < 3 && j < 3)
			{
				(*inverse)[i][j] = origin[(i + 1) % 3][(j + 1) % 3] * origin[(i + 2) % 3][(j + 2) % 3];
				(*inverse)[i][j] -= origin[(i + 1) % 3][(j + 2) % 3] * origin[(i + 2) % 3][(j + 1) % 3];
				(*inverse)[i][j] *= determinant;
			}
			else
				(*inverse)[i][j] = origin[i][j];
			j++;
		}
		i++;
	}
	return (inverse);
}
