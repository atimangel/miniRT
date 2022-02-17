/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:22:51 by snpark            #+#    #+#             */
/*   Updated: 2022/02/16 16:45:11 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_bool is_rtfile(char *filename)
{
	const char *extension = ".rt";

	while (*(filename + 3))
		++filename;
	while (*filename)
		if (*extension++ != *filename++)
			return (FALSE);
	return (TRUE);
}

char	*get_next_line(int fd)
{
	static char		buffer[1024];
	static int		offset = 0;
	int				readlen;

	if (offset == 0)
	{
		readlen = read(fd, buffer, 1024);
		if (readlen == -1)
			exit(1);
		else if (readlen == 0)
			return (NULL);
	}
}

t_rt	*parse(char *filename)
{
	t_rt	*format;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit(1);

	return (format);
}

int	main(int argc, char **argv)
{
	t_rt	*img_format;

	if (argc != 2 || !is_rtfile(argv[1]))
		return (1);
	img_format = parse(argv[1]);
}
