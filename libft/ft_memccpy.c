/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 13:25:52 by snpark            #+#    #+#             */
/*   Updated: 2020/12/24 16:35:40 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*dest_cpy;
	unsigned char	*src_cpy;
	size_t			i;

	i = 0;
	dest_cpy = (unsigned char *)dest;
	src_cpy = (unsigned char *)src;
	while (i < n)
	{
		*dest_cpy = *src_cpy;
		dest_cpy++;
		if (*src_cpy == (unsigned char)c)
			return (dest_cpy);
		src_cpy++;
		i++;
	}
	return (0);
}

/*
**dest - This is pointer to copy data from src. data-casting void*.
**src - This is pointer haver data to copy. data-casting void*.
**n - This is number of bytes to copy.
**c - This is last character to copy.
**return - if c is copied, return pointer to char in dest
**	that immediately follows the chara1cter.
**	if c is not copied, it returns NULL.
*/
