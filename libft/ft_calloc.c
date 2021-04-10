/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 17:37:39 by snpark            #+#    #+#             */
/*   Updated: 2020/12/24 09:01:28 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*ptr;

	if (!(ptr = malloc(nitems * size)))
		return (0);
	ft_bzero(ptr, nitems * size);
	return (ptr);
}

/*
**funtion
**allocate memory and return pointer
**malloc does not set memory to 0
**calloc set memory to 0
**parmeter
**nitems - Number of elements to be allocated
**size - size of elements. byte.
**return pointer to the allocated memory
**return
**pointer to the allocated memory
**if request fail return NULL
*/
