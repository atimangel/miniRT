/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 13:13:08 by snpark            #+#    #+#             */
/*   Updated: 2021/01/11 14:33:45 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_bonus.h"

static int	sub_get(char **dest, char *src, char **save)
{
	char *tmp;

	tmp = *dest;
	*dest = ft_strjoin(*dest, src);
	free(tmp);
	if (!*dest)
		return (-1);
	if (ft_strchr(src, '\n') != 0)
	{
		tmp = *dest;
		*dest = ft_substr(*dest, 0, ft_strchr(*dest, '\n') - *dest);
		free(tmp);
		if (!*dest)
			return (-1);
		if (ft_strchr(src, '\n') != src + ft_strlen(src) - 1)
		{
			*save = ft_substr(src, ft_strchr(src, '\n') - src + 1,
					ft_strlen(src) - (ft_strchr(src, '\n') - src)- 1);
			if (!*save)
				return (-1);
		}
		return (1);
	}
	return (0);

}

static void	ft_free_save(char *tmp, char **save)
{
	free(tmp);
	if (*save == tmp)
		*save = 0;
}

int			get_next_line(int fd, char **line)
{
	int			readnum;
	char		buf[BUFFER_SIZE + 1];
	static char	*save;
	char		*tmp;
	int			return_subget;

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	*line = ft_substr("", 0, 0);
	if (save)
	{
		tmp = save;
		return_subget = sub_get(line, save, &save);
		ft_free_save(tmp, &save);
		if (return_subget != 0)
			return (return_subget);
	}
	while ((readnum = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[readnum] = '\0';
		return_subget = sub_get(line, buf, &save);
		if (return_subget != 0)
			return (return_subget);
	}
	return (readnum > 0 ? 1 : readnum);
}
