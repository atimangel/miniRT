/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjakim <minjakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 11:07:20 by minjakim          #+#    #+#             */
/*   Updated: 2022/02/19 11:16:49 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	*xcalloc(size_t bytes)
{
	void	*ptr;

	ptr = malloc(bytes);
	if (!ptr)
		report_error("malloc failed\n");
	ft_memset(ptr, 0, bytes);
	return (ptr);
}

void
	xfree(void *obj)
{
	if (obj)
		free(obj);
}

int	xopen(const char *path, int oflag)
{
	const int	fd = open(path, oflag);

	if (oflag == -1)
		report_error("open error\n");
	return (fd);
}

ssize_t	xread(int filedes, void *buf, size_t nbyte)
{
	const ssize_t	readlen = read(filedes, buf, nbyte);

	if (readlen == -1)
		report_error("read error\n");
	return (readlen);
}
