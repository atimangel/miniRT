/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:53:46 by snpark            #+#    #+#             */
/*   Updated: 2020/12/25 10:32:59 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int c, size_t count)
{
	size_t			i;
	unsigned char	*buffer;

	buffer = (unsigned char *)buf;
	i = 0;
	while (i < count && buffer[i] != (unsigned char)c && buffer[i])
		i++;
	if (buffer[i] == (unsigned char)c && i < count)
		return (buffer + i);
	return (0);
}

/*
**find c in buffer check n bytes
**return char's pointer in string
**else return 0
*/
