/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:41:50 by hyojulee          #+#    #+#             */
/*   Updated: 2022/08/29 20:39:10 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list		*del_node;

	if (*lst == NULL)
		return ;
	while (*lst != NULL)
	{
		del_node = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(del_node, del);
	}
}
