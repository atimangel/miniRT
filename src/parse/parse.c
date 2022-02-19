/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:14:12 by snpark            #+#    #+#             */
/*   Updated: 2022/02/19 12:24:40 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_bool	is_rtfile(char *filename)
{
	const char	*extension = ".rt";

	while (*(filename + 3))
		++filename;
	while (*filename)
		if (*extension++ != *filename++)
			return (FALSE);
	return (TRUE);
}

void	skip_space(const char **str)
{
	while (**str == ' ' || **str == '\t')
		++(*str);
}

void	parse_exception(const char *line, t_bool is_parsed)
{
	if (is_parsed)
		return ;
	while (*line == ' ' || *line == '\t')
		++line;
	if (*line)
		report_error("format error\n");
}

void	parse(const char *const filename, t_rt *const img_format)
{
	int		fd;
	char	*line;
	t_bool	is_parsed;

	fd = xopen(filename, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		is_parsed = FALSE;
		parse_light((const char *)line, img_format, &is_parsed);
		parse_camera((const char *)line, img_format, &is_parsed);
		parse_ambient((const char *)line, img_format, &is_parsed);
		parse_sphere((const char *)line, img_format, &is_parsed);
		parse_plane((const char *)line, img_format, &is_parsed);
		parse_cylinder((const char *)line, img_format, &is_parsed);
		parse_exception((const char *)line, is_parsed);
		xfree(line);
	}
	if (!img_format->count.ambient || !img_format->count.camera || \
			!img_format->count.light)
		report_error("camera, ambient, light must assign one time\n");
}
