/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 20:05:53 by snpark            #+#    #+#             */
/*   Updated: 2020/12/28 21:35:57 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_count_chapter(char const *s, char c)
{
	char	**book;
	int		chapter;
	int		pages;
	int		i;

	i = 0;
	chapter = 0;
	pages = 0;
	while (s[i])
	{
		if (s[i] == c && pages != 0)
		{
			chapter++;
			pages = 0;
		}
		if (s[i] != c)
			pages++;
		i++;
	}
	if (pages != 0)
		chapter++;
	if (!(book = (char **)malloc(sizeof(char *) * (chapter + 1))))
		return (0);
	book[chapter] = 0;
	return (book);
}

static int	ft_count_pages(char const *s, char c, char **book)
{
	int	start;
	int	pages;
	int i;
	int	chapter;

	chapter = 0;
	i = 0;
	start = 0;
	pages = 0;
	while (s[i])
	{
		if (s[i] == c && pages != 0)
		{
			if (!(book[chapter] = ft_substr(s, start, pages)))
				return (0);
			pages = 0;
			chapter++;
		}
		start = (s[i] != c && pages == 0) ? i : start;
		pages = (s[i] != c) ? pages + 1 : pages;
		i++;
	}
	if (pages != 0 && (!(book[chapter] = ft_substr(s, start, pages))))
		return (0);
	return (1);
}

char		**ft_split(char const *s, char c)
{
	char	**book;
	int		i;

	i = -1;
	if (!s)
		return (0);
	if (!(book = ft_count_chapter(s, c)))
		return (0);
	if (!(ft_count_pages(s, c, book)))
	{
		while (book[++i])
			free(book[i]);
		free(book);
		return (0);
	}
	return (book);
}
