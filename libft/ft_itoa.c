/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 10:54:52 by snpark            #+#    #+#             */
/*   Updated: 2020/12/27 18:46:27 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_magnitude(int n)
{
	int	magnitude;

	if (!n)
		return (1);
	magnitude = n > 0 ? 0 : 1;
	while (n)
	{
		magnitude++;
		n /= 10;
	}
	return (magnitude);
}

char		*ft_itoa(int n)
{
	char	*deca;
	int		magnitude;

	magnitude = ft_count_magnitude(n);
	if (!(deca = (char *)malloc(magnitude + 1)))
		return (0);
	deca[magnitude--] = 0;
	deca[0] = n < 0 ? '-' : 0;
	while (magnitude >= 0 && deca[magnitude] != '-')
	{
		if (n >= 0)
			deca[magnitude] = n % 10 + '0';
		else
			deca[magnitude] = -1 * (n % 10) + '0';
		n /= 10;
		magnitude--;
	}
	return (deca);
}
