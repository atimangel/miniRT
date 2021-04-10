/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 11:20:03 by snpark            #+#    #+#             */
/*   Updated: 2020/12/28 14:47:30 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	join_len;

	if (!s1 || !s2)
		return (0);
	join_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(join = (char *)malloc(join_len)))
		return (0);
	ft_bzero(join, join_len);
	ft_strlcpy(join, s1, ft_strlen(s1) + 1);
	ft_strlcat(join, s2, join_len);
	return (join);
}
