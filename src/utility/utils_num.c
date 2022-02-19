/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:57:06 by snpark            #+#    #+#             */
/*   Updated: 2022/02/19 11:16:01 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <limits.h>

static t_bool	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

static void	atoscala_preprocess(const char **s, t_bool *neg)
{
	while (**s == ' ' || **s == '\t')
		++(*s);
	*neg = (**s == '-');
	if (*neg)
		++(*s);
	if (!is_digit(**s))
		report_error("scala format error\n");
}

int	ft_atoi(const char **s)
{
	int		num;
	t_bool	neg;

	atoscala_preprocess(s, &neg);
	num = 0;
	while (is_digit(**s))
	{
		num = num * 10 + **s - '0';
		if ((neg && (unsigned int)num - 1 > INT_MAX) || \
				(!neg && (unsigned int)num > INT_MAX))
			report_error("value is out of int rage\n");
		++(*s);
	}
	if (neg)
		num *= -1;
	return (num);
}

static float	decimal_part(const char **s)
{
	float	num;
	float	decimal_position;

	decimal_position = 0.1;
	num = 0.0;
	while (is_digit(**s))
	{
		num += (**s - '0') * decimal_position;
		decimal_position *= 0.1;
		++(*s);
	}
	return (num);
}

float	ft_atof(const char **s)
{
	float	num;
	t_bool	neg;

	atoscala_preprocess(s, &neg);
	num = 0.0f;
	while (is_digit(**s))
	{
		num = num * 10.0f + **s - '0';
		++(*s);
	}
	if (**s == '.')
		++(*s);
	num += decimal_part(s);
	if (neg)
		num *= -1.0f;
	return (num);
}
