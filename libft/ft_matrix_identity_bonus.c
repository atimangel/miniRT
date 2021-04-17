#include "libft_bonus.h"

t_a16	*ft_matrix_identity(void)
{
	t_a16	*identity;
	int		i;
	int		j;

	identity = (t_a16 *)malloc(sizeof(t_a16));
	if (!identity)
		return (0);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i == j)
				(*identity)[i][j] = 1;
			else
				(*identity)[i][j] = 0;
			j++;
		}
		i++;
	}
	return (identity);
}
