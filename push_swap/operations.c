/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:48:53 by hyojulee          #+#    #+#             */
/*   Updated: 2022/11/10 19:25:01 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap(t_stack *stack)
{
	int	top;
	int	top_next;

	if (stack->current_index == -1)
		return ;
	top = pop(stack);
	top_next = pop(stack);
	push(stack, top);
	push(stack, top_next);
}

void	reverse_rotate(t_stack *stack)
{
	int	next;
	int	index;
	int	temp;

	index = stack->current_index - 1;
	next = stack->arr[stack->current_index];
	stack->arr[stack->current_index] = stack->arr[0];
	while (index >= 0)
	{
		temp = stack->arr[index];
		stack->arr[index] = next;
		if (index >= 1)
			next = temp;
		index--;
	}
}

void	rotate(t_stack *stack)
{
	int	next;
	int	index;
	int	temp;

	index = 1;
	next = stack->arr[0];
	stack->arr[0] = stack->arr[stack->current_index];
	while (index <= stack->current_index)
	{
		temp = stack->arr[index];
		stack->arr[index] = next;
		if (index < stack->current_index)
			next = temp;
		index++;
	}
}

void	push_from_another_stack(t_stack *stack, t_stack *another)
{
	if (another->current_index == -1)
		return ;
	push(stack, pop(another));
}
