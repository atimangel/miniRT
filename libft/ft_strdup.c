/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:58:42 by snpark            #+#    #+#             */
/*   Updated: 2020/12/25 13:57:30 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char *ptr;

	if (!(ptr = (char *)malloc(ft_strlen(str) + 1)))
		return (0);
	ptr = ft_memcpy(ptr, str, ft_strlen(str) + 1);
	ptr[ft_strlen(str)] = 0;
	return (ptr);
}

/*
**duplicate a string
**str - string to dupicate
**return new string's pointer
**if error occur null return
*/
