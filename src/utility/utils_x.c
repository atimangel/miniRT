/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjakim <minjakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 11:07:20 by minjakim          #+#    #+#             */
/*   Updated: 2022/02/16 16:49:31 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	*xcalloc(size_t bytes)
{
	void	*ptr;

	ptr = malloc(bytes);
	if (!ptr)
		;//report_error_fatal(errno);
	ft_memset(ptr, 0, bytes);
	return (ptr);
}

void
	xfree(void *obj)
{
	if (obj)
		free(obj);
}
