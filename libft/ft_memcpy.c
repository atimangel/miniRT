/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 12:36:49 by snpark            #+#    #+#             */
/*   Updated: 2020/12/24 16:12:05 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *src_cpy;
	unsigned char *dest_cpy;

	if (dest == 0 && src == 0)
		return (NULL);
	src_cpy = (unsigned char *)src;
	dest_cpy = dest;
	while (n--)
	{
		*dest_cpy = *src_cpy;
		dest_cpy++;
		src_cpy++;
	}
	return (dest);
}

/*
**dest - This is pointer the destination array where the content to be copied,
**	type-cated to a pointer of type void*.
**src - Tis is pointer to the source of data to be copied,
**	type-casted to a pointer of type void*.
**n - This is the number of bytes to be copied.
**return poiner to destination.
*/
