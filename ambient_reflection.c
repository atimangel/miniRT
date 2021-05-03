#include "minirt.h"

void	*ft_make_ambient_reflection(char *line)
{
	t_ambient_reflection *amb;

	amb = (t_ambient_reflection *)malloc(sizeof(t_ambient_reflection));
	if (!amb)
		printf("error\namb_ref malloc error\n");
	line += 1;
	while (*line == ' ')
		line++;
	if (*line == '-' || *line == '+' || ft_isdigit(*line))
		amb->ratio = ft_atof(line);
	while (ft_isdigit(*line))
		line++;
	if (*line == '.')
		line++;
	while(ft_isdigit(*line))
		line++;
	while (*line == ' ')
		line++;
	if (ft_isdigit(*line))
		amb->red = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	if (*line == ',')
		line++;
	if (ft_isdigit(*line))
		amb->green = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	if (*line == ',')
		line++;
	if (ft_isdigit(*line))
		amb->blue = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	while (*line == ' ')
		line++;
	printf("%s\n", line);
	if (*line != '\0')
		printf("error\nstring's blank should be space and end is null character\nAmb_ref");
	if (amb->ratio < 0.0 || amb->ratio > 1.0)
		printf("error\namb ratio should be in 0.0 ~ 1.0");
	amb->id = A;
	return(amb);
//형식에 맞춰서 안적을 경우
//범위를 넘어서는 값을 적을 경우
}

void	ft_ambient_reflection(t_pixel_unit *u, t_list *obj)
{
	t_ambient_reflection *amb;

	while (((t_ambient_reflection *)obj->content)->id != A)
		obj = obj->next;
	if (obj != 0 && ((t_ambient_reflection *)obj->content)->id == A)
		amb = obj->content;
	u->p_r = u->o_r * amb->ratio * amb->red / 255;
	u->p_g = u->o_g * amb->ratio * amb->green / 255;
	u->p_b = u->o_b * amb->ratio * amb->blue / 255;
}
