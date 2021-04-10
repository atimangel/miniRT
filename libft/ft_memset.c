/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 16:38:36 by snpark            #+#    #+#             */
/*   Updated: 2020/12/24 10:02:52 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char *str_cpy;

	str_cpy = (unsigned char *)str;
	while (n--)
		*str_cpy++ = (unsigned char)c;
	return (str);
}

/*
**str - This is a pinter to the block of memory to fill
**c - This is the value to be set. The value is passed as an int,
**	but function fills the block of memory using
**	unsigned char conversion of this value.
**n - This is the number of bytes to ne set the value.
**unsigned char is a byte
**repeat n to 1
*/
