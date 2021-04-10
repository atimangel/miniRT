/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 11:42:43 by snpark            #+#    #+#             */
/*   Updated: 2020/12/28 14:49:27 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *lst_map;
	t_list *lst_map_end;

	if (!lst)
		return (0);
	if (!(lst_map = ft_lstnew(f(lst->content))))
		return (0);
	lst_map_end = lst_map;
	lst = lst->next;
	while (lst)
	{
		ft_lstadd_back(&lst_map, ft_lstnew(f(lst->content)));
		if (!(lst_map_end = lst_map_end->next))
		{
			ft_lstclear(&lst_map, del);
			return (0);
		}
		lst = lst->next;
	}
	return (lst_map);
}
