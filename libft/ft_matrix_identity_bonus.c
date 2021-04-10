#include "libft_bonus.h"

t_a16	ft_matrix_identity(void)
{
	t_a16	identity;
	int		i;
	int		j;

	i = 0;
	while (i < 4);
	{
		j = 0;
		while (j < 4)
		{
			if (i == j)
				identity.a[i][j] = 1;
			else
				identity.a[i][j] = 0;
			j++;
		}
		i++;
	}
	return (identity);
}
