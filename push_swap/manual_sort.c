/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:53:10 by hyojulee          #+#    #+#             */
/*   Updated: 2022/11/23 14:13:45 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "operations.h"
#include "compare.h"

void	manual_sort(t_pushswap *answer)
{
	if (answer->stacks[answer->which_case]->current_index < 1)
		return ;
	if (answer->stacks[answer->which_case]->current_index == 1)
		manual_sort_with_2(answer);
	else if (answer->which_case == A_CASE
		&& answer->stacks[A_CASE]->current_index == 2)
		manual_sort_with_3(answer);
	else if (answer->which_case == A_CASE)
		manual_sort_a(answer,
			answer->stacks[A_CASE]->current_index - 2,
			answer->stacks[A_CASE]->current_index);
	else if (answer->which_case == B_CASE)
		manual_sort_b(answer,
			answer->stacks[B_CASE]->current_index - 2,
			answer->stacks[B_CASE]->current_index);
}

void	push_swap_push(t_pushswap *answer, int which_case)
{
	if (which_case == A_CASE)
	{
		pb(answer);
		sa(answer);
		pa(answer);
	}
	else
	{
		pa(answer);
		sb(answer);
		pb(answer);
	}
}

void	manual_sort_a(t_pushswap *answer, int start, int end)
{
	t_stack	*stack;

	stack = answer->stacks[A_CASE];
	if (is_lowhighmid(stack->arr[start], stack->arr[end - 1], stack->arr[end]))
	{
		push_swap_push(answer, A_CASE);
		sa(answer);
	}
	if (is_midhighlow(stack->arr[start], stack->arr[end - 1], stack->arr[end]))
		push_swap_push(answer, A_CASE);
	if (is_midlowhigh(stack->arr[start], stack->arr[end - 1], stack->arr[end]))
	{
		sa(answer);
		push_swap_push(answer, A_CASE);
	}
	if (is_highlowmid(stack->arr[start], stack->arr[end - 1], stack->arr[end]))
		sa(answer);
	if (is_lowmidhigh(stack->arr[start], stack->arr[end - 1], stack->arr[end]))
	{
		sa(answer);
		push_swap_push(answer, A_CASE);
		sa(answer);
	}
}

void	manual_sort_b(t_pushswap *answer, int start, int end)
{
	t_stack	*stack;

	stack = answer->stacks[B_CASE];
	if (is_lowhighmid(stack->arr[start], stack->arr[end - 1], stack->arr[end]))
		sb(answer);
	if (is_midhighlow(stack->arr[start], stack->arr[end - 1], stack->arr[end]))
	{
		sb(answer);
		push_swap_push(answer, B_CASE);
	}
	if (is_midlowhigh(stack->arr[start], stack->arr[end - 1], stack->arr[end]))
		push_swap_push(answer, B_CASE);
	if (is_highlowmid(stack->arr[start], stack->arr[end - 1], stack->arr[end]))
	{
		push_swap_push(answer, B_CASE);
		sb(answer);
	}
	if (is_highmidlow(stack->arr[start], stack->arr[end - 1], stack->arr[end]))
	{
		sb(answer);
		push_swap_push(answer, B_CASE);
		sb(answer);
	}
}

void	manual_sort_with_2(t_pushswap *answer)
{
	int		index;

	if (answer->stacks[answer->which_case]->current_index == 0)
		return ;
	index = answer->stacks[answer->which_case]->current_index;
	if (answer->stacks[answer->which_case]->arr[index]
		> answer->stacks[answer->which_case]->arr[index - 1])
	{
		if (answer->which_case == A_CASE)
			sa(answer);
	}
	else
	{
		if (answer->which_case == B_CASE)
			sb(answer);
	}
}
