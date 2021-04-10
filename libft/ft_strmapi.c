/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 15:32:32 by snpark            #+#    #+#             */
/*   Updated: 2020/12/27 18:56:47 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*mapi;
	unsigned int		i;

	if (!s || !f)
		return (0);
	i = 0;
	if (!(mapi = ft_strdup(s)))
		return (0);
	while (mapi[i])
	{
		mapi[i] = f(i, mapi[i]);
		i++;
	}
	return (mapi);
}
