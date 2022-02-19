/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:13:28 by snpark            #+#    #+#             */
/*   Updated: 2022/02/19 11:17:36 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

char	*ft_strcpy(char *dst, const char *src)
{
	const char *const	dst_head = dst;

	if (!dst || !src || !*src)
		return ((char *)dst_head);
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
	return ((char *)dst_head);
}

char	*ft_strcat(char *dst, const char *src)
{
	const char *const	dst_head = dst;

	if (!dst || !src || !*src)
		return ((char *)dst_head);
	while (*dst)
		++dst;
	ft_strcpy(dst, src);
	return ((char *)dst_head);
}

char	*ft_strncat(char *dst, const char *src, size_t len)
{
	const char *const	dst_head = dst;

	if (!dst || !src || !*src)
		return ((char *)dst_head);
	while (*dst)
		++dst;
	ft_strncpy(dst, src, len);
	return ((char *)dst_head);
}

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t				i;
	const char *const	dst_head = dst;

	if (!dst || !src || !*src)
		return ((char *)dst_head);
	i = -1;
	while (++i < len && src[i])
		dst[i] = src[i];
	while (i < len)
		dst[i++] = '\0';
	return ((char *)dst_head);
}

void	ft_strmove(char *str, unsigned int move)
{
	while (*str || *(str + move))
	{
		*str = *(str + move);
		str++;
	}
	*str = '\0';
}
