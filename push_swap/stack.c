/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:40:05 by hyojulee          #+#    #+#             */
/*   Updated: 2022/11/10 19:44:40 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "pushswap.h"

t_stack	*init_stack_with_arr(int *arr, int size)
{
	t_stack	*stack;
	int		index;
	int		last_index;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->arr = (int *)malloc(sizeof(int) * size);
	stack->current_index = size - 1;
	index = 0;
	last_index = size - 1;
	while (index < size)
	{
		stack->arr[index] = arr[last_index];
		index++;
		last_index--;
	}
	return (stack);
}

t_stack	*create_empty_stack(int size)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->arr = (int *)malloc(sizeof(int) * size);
	stack->current_index = -1;
	return (stack);
}

int	pop(t_stack *stack)
{
	int	temp;

	if (stack->current_index == -1)
		return (-1);
	temp = stack->arr[stack->current_index];
	stack->current_index -= 1;
	return (temp);
}

void	push(t_stack *stack, int value)
{
	stack->current_index++;
	stack->arr[stack->current_index] = value;
}

int	peek(t_stack *stack)
{
	return (stack->arr[stack->current_index]);
}
