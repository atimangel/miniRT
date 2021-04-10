/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:42:55 by snpark            #+#    #+#             */
/*   Updated: 2020/12/25 10:12:27 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *string1, const char *string2, size_t count)
{
	size_t i;

	i = 0;
	if (!count)
		return (0);
	while (i < count && (string1[i] || string2[i]) && string1[i] == string2[i])
		i++;
	if (i == count && i && (string1[i - 1] == string2[i - 1]))
		return (0);
	return ((unsigned char)string1[i] - (unsigned char)string2[i]);
}
