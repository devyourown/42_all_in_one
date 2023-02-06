/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:42:24 by hyojulee          #+#    #+#             */
/*   Updated: 2022/08/29 20:35:57 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*result_head;

	if (lst == NULL)
		return (NULL);
	result = ft_lstnew(f(lst->content));
	result_head = result;
	if (result == NULL)
		ft_lstdelone(result, del);
	while (lst->next != NULL)
	{
		result->next = ft_lstnew(f(lst->next->content));
		if (result->next == NULL)
			ft_lstclear(&result_head, del);
		result = result->next;
		lst = lst->next;
	}
	return (result_head);
}
