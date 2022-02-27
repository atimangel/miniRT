/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mem_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjakim <minjakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:38:12 by minjakim          #+#    #+#             */
/*   Updated: 2022/02/25 15:10:55 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt_bonus.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*s_ptr;

	s_ptr = s;
	while (n--)
		*s_ptr++ = c;
	return (s);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst_write;
	const char	*src_write;
	const int	ll_size = sizeof(long long);

	dst_write = dst;
	src_write = src;
	if (!dst || !src || dst == src)
		return (dst);
	while (n)
	{
		if (n >= ll_size)
		{
			n -= ll_size;
			*(long long *)dst_write = *(long long *)src_write;
			dst_write += ll_size;
			src_write += ll_size;
		}
		else
		{
			n--;
			*dst_write++ = *src_write++;
		}
	}
	return (dst);
}
