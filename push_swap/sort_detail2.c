/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_detail2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:01:19 by hyojulee          #+#    #+#             */
/*   Updated: 2022/11/23 16:28:43 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "operations.h"

void	split_a_three_part(t_pushswap *answer, int left, int right)
{
	int		a_thrid;
	int		big_pivot;
	int		small_pivot;

	if (right - left < 3)
	{
		manual_sort(answer);
		return ;
	}
	a_thrid = (right - left) / 3;
	push(answer->pivot_stack, a_thrid);
	big_pivot = answer->sorted_arr[left + (a_thrid * 2)];
	small_pivot = answer->sorted_arr[left + a_thrid];
	send_to_b_stack(answer, small_pivot, a_thrid);
	send_to_b_stack(answer, big_pivot, a_thrid);
	split_a_three_part(answer, left + (a_thrid * 2), right);
}

void	send_to_b_stack(t_pushswap *answer, int pivot, int size)
{
	int		max;

	max = answer->stacks[A_CASE]->current_index + 1;
	while (size && max)
	{
		if (answer->stacks[A_CASE]->arr[answer->stacks[A_CASE]->current_index]
			< pivot)
		{
			pb(answer);
			size--;
		}
		else
			ra(answer);
		max--;
	}
}

void	split_b_three_part(t_pushswap *answer, int left, int right)
{
	int		count;

	count = right - left;
	if (left < 0)
		left = 0;
	if (right < left)
		return ;
	if (count < 3)
	{
		while (right >= left)
		{
			pa(answer);
			right--;
		}
		manual_sort_in_a(answer, count);
		return ;
	}
	send_to_a_stack(answer, get_pivot(answer, B_CASE), 3);
	manual_sort_in_a(answer, 2);
	split_b_three_part(answer, left, right - 3);
}

void	send_to_a_stack(t_pushswap *answer, int pivot, int size)
{
	int		count;

	count = 0;
	while (size)
	{
		if (answer->stacks[B_CASE]->arr[answer->stacks[B_CASE]->current_index]
			>= pivot)
		{
			pa(answer);
			size--;
		}
		else
		{
			rb(answer);
			count++;
		}
	}
	while (count)
	{
		rrb(answer);
		count--;
	}
}

void	manual_sort_in_a(t_pushswap *answer, int count)
{
	int		a_current_index;

	a_current_index = answer->stacks[A_CASE]->current_index;
	if (count == 1)
		manual_sort_with_2(answer);
	else if (count == 2)
		manual_sort_a(answer, a_current_index - 2, a_current_index);
}
