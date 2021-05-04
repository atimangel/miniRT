#include "minirt.h"

char	*ft_read_float(char *line, double *vec, char flag)
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

char	*ft_read_char(char *line, char *rgb, char flag)
{
	int	color;

	if (*line == '-' || *line == '+' || ft_isdigit(*line))
	{
		color = ft_atoi(line);
		if (color < 0 || color > 255)
			printf("error\nrgb over or under the range\n");
		line++;
		while(ft_isdigit(*line))
			line++;
		if (flag && *line == ',')
			line++;
		*rgb = color;
	}
	return (line);
}
