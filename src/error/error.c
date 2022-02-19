/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:38:49 by snpark            #+#    #+#             */
/*   Updated: 2022/02/19 11:10:24 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	report_error(const char *str)
{
	write(STDERR_FILENO, "ERROR\n", 6);
	write(STDERR_FILENO, str, ft_strlen(str));
	exit(1);
}
