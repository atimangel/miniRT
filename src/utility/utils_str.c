/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:00:28 by snpark            #+#    #+#             */
/*   Updated: 2022/02/16 17:23:14 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int		ft_strcmp(const unsigned char *s1, const unsigned char *s2)
{
	while (*s1 && *s2 && *s1++ == *s2++);
	return (*s1 - *s2);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != c)
		++s;
	return ((char *)s);
}

int		ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i++]);
	return (i);
}
