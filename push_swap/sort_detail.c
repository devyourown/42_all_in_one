/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_detail.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:18:29 by hyojulee          #+#    #+#             */
/*   Updated: 2022/11/23 16:23:06 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "operations.h"

void	sort(t_pushswap *answer)
{
	if (answer->stacks[A_CASE]->current_index <= 2)
	{
		manual_sort(answer);
		return ;
	}
	if (answer->stacks[A_CASE]->current_index == 4)
	{
		manual_sort_with_5(answer);
		return ;
	}
	split_a_three_part(answer, 0, answer->size - 1);
	while (answer->pivot_stack->current_index >= 0)
	{
		send_to_a(answer);
	}
}

void	send_to_a(t_pushswap *answer)
{
	int		size;
	int		b_index;

	size = pop(answer->pivot_stack);
	b_index = answer->stacks[B_CASE]->current_index;
	split_b_three_part(answer, b_index - size + 1, b_index);
	split_b_three_part(answer, b_index - (size * 2) + 1, b_index - size);
}
