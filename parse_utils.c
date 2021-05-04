#include "minirt.h"

char	*ft_read_vec3(char *line, double *vec, char flag)
{
	if(*line == '-' || *line == '+' || ft_isdigit(*line))
	{
		*vec = ft_atof(line);
		line++;
		while(ft_isdigit(*line))
			line++;
		if (*line == '.')
			line++;
		while(ft_isdigit(*line))
			line++;
		if (flag && *line == ',')
			line++;
	}
	return (line);
}

char	*ft_pass_space(char *line)
{
	while (*line == ' ')
		line++;
	return (line);
}
