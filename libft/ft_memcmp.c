/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:37:11 by snpark            #+#    #+#             */
/*   Updated: 2020/12/25 10:34:32 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	size_t			i;
	unsigned char	*buffer1;
	unsigned char	*buffer2;

	buffer1 = (unsigned char *)buf1;
	buffer2 = (unsigned char *)buf2;
	i = 0;
	while (i < count && buffer1[i] == buffer2[i])
		i++;
	if (i < count)
		return (buffer1[i] - buffer2[i]);
	return (0);
}
/*
**Compares the first n bytes of buf1 and buf2.
**buf1 - First buffer.
**buf2 - Second buffer.
**n - Number of characters to compare.
**Return buf1 > buf2 +
**	buf1 = buf2 0
**	buf1 < buf2 -
*/
