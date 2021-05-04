/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 16:16:29 by snpark            #+#    #+#             */
/*   Updated: 2020/12/28 10:00:31 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static	int	ft_ispm(char c)
{
	if (c == '+')
		return (1);
	else if (c == '-')
		return (-1);
	return (0);
}

double			ft_atof(const char *string)
{
	int			i;
	double			number;
	double			under_dot;

	i = 0;
	number = ft_atoi(string);
	under_dot = 0;
	while (ft_isspace(string[i]))
		i++;
	if (ft_ispm(string[i]))
		i++;
	while (ft_isdigit(string[i]))
		i++;
	if (string[i] == '.' && ft_isdigit(string[i + 1]))
	{
		i++;
		under_dot = ft_atoi(string + i);
		while (under_dot >= 1.0)
			under_dot /= 10;
	}
	number += under_dot;
	return (number);
}
