/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:15:36 by snpark            #+#    #+#             */
/*   Updated: 2022/02/25 15:10:55 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt_bonus.h"

static t_bool	read_file(ssize_t *offset, ssize_t *readlen, int fd, char *buf)
{
	if (*offset == *readlen)
	{
		*offset = 0;
		*readlen = xread(fd, buf, BUFFER_SIZE);
		if (*readlen == 0)
			return (FALSE);
	}
	return (TRUE);
}

char	*gnl_strcat(char *line, char *buffer, ssize_t offset, int i)
{
	char	*tmp;

	if (!line)
		return (ft_strndup(buffer + offset, i));
	else
	{
		tmp = line;
		line = xcalloc(ft_strlen(tmp) + i + 1);
		line = ft_strncat(ft_strcpy(line, tmp), buffer + offset, i);
		xfree(tmp);
		return (line);
	}
}

t_bool	get_next_line(int fd, char **dest)
{
	static char		buffer[BUFFER_SIZE + 1];
	static ssize_t	offset = BUFFER_SIZE;
	static ssize_t	readlen = BUFFER_SIZE;
	int				i;
	char			*line;

	line = NULL;
	buffer[BUFFER_SIZE] = '\0';
	while (TRUE)
	{
		if (!read_file(&offset, &readlen, fd, buffer))
			return (FALSE);
		i = -1;
		while (buffer[offset + ++i] != '\n' && buffer[offset + i])
			;
		line = gnl_strcat(line, buffer, offset, i);
		offset = offset + i;
		if (buffer[offset] == '\n')
		{
			++offset;
			*dest = line;
			return (TRUE);
		}
	}
}
