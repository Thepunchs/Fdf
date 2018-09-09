/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 17:17:53 by alefebvr          #+#    #+#             */
/*   Updated: 2017/11/19 18:39:19 by alefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *list;
	t_list *fraiche;
	t_list *next;

	if (!lst || !f)
		return (NULL);
	next = f(lst);
	if ((list = ft_lstnew(next->content, next->content_size)) == NULL)
		return (NULL);
	lst = lst->next;
	fraiche = list;
	while (lst != NULL)
	{
		next = f(lst);
		if ((list->next = ft_lstnew(next->content, next->content_size)) == NULL)
			return (NULL);
		list = list->next;
		lst = lst->next;
	}
	return (fraiche);
}
