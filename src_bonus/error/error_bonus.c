/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:38:49 by snpark            #+#    #+#             */
/*   Updated: 2022/02/25 15:07:39 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt_bonus.h"

void	report_error(const char *str)
{
	write(STDERR_FILENO, "ERROR\n", 6);
	write(STDERR_FILENO, str, ft_strlen(str));
	exit(1);
}
