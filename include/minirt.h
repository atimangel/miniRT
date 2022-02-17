/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:21:50 by snpark            #+#    #+#             */
/*   Updated: 2022/02/17 16:35:34 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include "./type.h"

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int		ft_strlen(const char *s);
int		ft_strcmp(const unsigned char *s1, const unsigned char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strcat(char *dst, const char *src);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t len);
void	ft_strmove(char *str, unsigned int move);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);

//utils x alloc and free
void	*xcalloc(size_t bytes);
void	xfree(void *obj);
//utils duplicate
#endif
