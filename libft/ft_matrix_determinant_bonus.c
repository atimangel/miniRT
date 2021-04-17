#include "libft_bonus.h"

t_a16		ft_matrix_determinant(t_a16	a)
{
	double	determinant;
	int		i;

	i = 0;
	determinant = 0.0;
	while (i < 3)
	{
		determinant += a[0][i] * a[1][(i + 1) % 3] * a[2][(i + 2) % 3];
		determinant -= a[0][i] * a[1][(i + 2) % 3] * a[2][(i + 1) % 3];
		i++;
	}
	return (determinant);
}
