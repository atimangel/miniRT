/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 11:33:56 by snpark            #+#    #+#             */
/*   Updated: 2020/12/28 10:12:46 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isset(char c, char const *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char			*trim;
	unsigned int	start;
	unsigned int	end;

	if (!s1 || !set)
		return (0);
	start = 0;
	end = 0;
	while (s1[start] && ft_isset(s1[start], set))
		start++;
	while (start + end < ft_strlen(s1) &&
			ft_isset(s1[ft_strlen(s1) - end - 1], set))
		end++;
	if (!(trim = ft_substr(s1, start, ft_strlen(s1) - (start + end))))
		return (0);
	return (trim);
}
