/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:49:52 by hyojulee          #+#    #+#             */
/*   Updated: 2022/12/16 22:04:49 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "../stack/stack.h"

void	sort_3(struct s_stack *a)
{
	if (is_highlowmid(a))
		swap(a);
	else if (is_lowmidhigh(a))
	{
		rotate(a);
		swap(a);
	}
	else if (is_lowhighmid(a))
		reverse_rotate(a);
	else if (is_midhighlow(a))
	{
		reverse_rotate(a);
		swap(a);
	}
	else if (is_midlowhigh(a))
		rotate(a);
}
