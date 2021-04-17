/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 16:13:39 by snpark            #+#    #+#             */
/*   Updated: 2020/12/27 18:48:43 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n > 9 || n < -9)
		ft_putnbr_fd(n / 10, fd);
	if (n >= -9 && n < 0)
		ft_putchar_fd('-', fd);
	ft_putchar_fd("0123456789"[n >= 0 ? n % 10 : -1 * (n % 10)], fd);
}