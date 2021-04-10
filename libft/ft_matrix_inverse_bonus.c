#include "libft_bonus.h"

//treat as 3*3 matrix
t_a16		ft_matrix_inverse(t_a16 origin, double determinant)
{
	t_a16	inverse;
	int		i;
	int		j;

	if (determinant == 0.0)
		return (0);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i < 3 && j < 3)
			{
				inverse.a[i][j] = 0.0;
				inverse.a[i][j] += origin.a[(i + 1) % 3][(j + 1) % 3] * origin.a[(i + 2) % 3][(j + 2) % 3];
				inverse.a[i][j] -= origin.a[(i + 1) % 3][(j + 2) % 3] * origin.a[(i + 2) % 3][(j + 1) % 3];
				inverse.a[i][j] *= determinant;
			}
			else
				inverse.a[i][j] = origin.a[i][j];
			j++;
		}
		i++;
	}
	return (inverse);
}
