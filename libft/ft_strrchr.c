/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:39:18 by snpark            #+#    #+#             */
/*   Updated: 2020/12/27 19:18:05 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	len;
	char	*str_cpy;

	len = ft_strlen(str);
	str_cpy = (char *)str;
	if (!c)
		return (str_cpy + len);
	while (len && str_cpy[len - 1] != (char)c)
		len--;
	if (len && str_cpy[len - 1] == (char)c)
		return (str_cpy + len - 1);
	return (0);
}
/*
**find character which last in string
**if find character in string rerturn that pointer.
**else return null
**c = treat as char
*/
