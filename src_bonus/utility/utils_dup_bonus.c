/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dup_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:11:13 by snpark            #+#    #+#             */
/*   Updated: 2022/02/25 15:10:55 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt_bonus.h"

char	*ft_strdup(const char *str)
{
	void	*dst;
	size_t	len;

	if (!str)
		return (NULL);
	len = ft_strlen(str) + 1;
	dst = xcalloc(sizeof(char) * len);
	return (ft_memcpy(dst, str, len));
}

char	*ft_strndup(const char *str, size_t n)
{
	char	*dst;

	if (!str)
		return (NULL);
	dst = xcalloc(sizeof(char) * (n + 1));
	return (ft_memcpy(dst, str, n));
}
