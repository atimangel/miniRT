/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:28:48 by snpark            #+#    #+#             */
/*   Updated: 2022/03/01 22:57:18 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt_bonus.h"

void	tangent_space(t_bump *bump)
{
	const t_vector	y_axis = {{0.0, 1.0, 0.0}};
	const t_vector	z_axis = {{0.0, 0.0, -1.0}};

	if (vec_scala(vec_cross(y_axis, bump->z)))
		bump->y = vec_normalize(vec_cross(bump->z, y_axis));
	else
		bump->y = vec_normalize(vec_cross(bump->z, z_axis));
	bump->x = vec_normalize(vec_cross(bump->y, bump->z));
}

t_bump	parse_bump(const char **line)
{
	t_bump	bump;
	int		i;

	ft_memset(&bump, 0, sizeof(t_bump));
	while (**line == ' ' || **line == '\t')
		++(*line);
	if (**line == 'b' && (*line)[1] == ':')
	{
		*line += 2;
		i = 0;
		while ((*line)[i] != ' ' && (*line)[i] != '\t' && (*line)[i] != '\0')
			++i;
		if (i == 0)
			report_error("bump map not found\n");
		bump.name = ft_strndup(*line, i);
		*line += i;
	}
	return (bump);
}
