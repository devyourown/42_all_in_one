/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_command2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:45:22 by hyojulee          #+#    #+#             */
/*   Updated: 2022/12/20 17:41:42 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

struct s_stack
{
	int		*stack;
	int		index;
	char	stack_name;
};


void	reverse_rotate(struct s_stack *stack)
{
	int	next;
	int	index;
	int	temp;

	index = stack->index - 1;
	next = stack->stack[stack->index];
	stack->stack[stack->index] = stack->stack[0];
	while (index >= 0)
	{
		temp = stack->stack[index];
		stack->stack[index] = next;
		if (index >= 1)
			next = temp;
		index--;
	}
	write(1, "rr", 2);
	write(1, &stack->stack_name, 1);
	write(1, "\n", 1);
}

void	reverse_rotate_all(struct s_stack *a, struct s_stack *b)
{
	reverse_rotate_without_print(a);
	reverse_rotate_without_print(b);
	write(1, "rrr\n", 4);
}

void	reverse_rotate_without_print(struct s_stack *stack)
{
	int	next;
	int	index;
	int	temp;

	index = stack->index - 1;
	next = stack->stack[stack->index];
	stack->stack[stack->index] = stack->stack[0];
	while (index >= 0)
	{
		temp = stack->stack[index];
		stack->stack[index] = next;
		if (index >= 1)
			next = temp;
		index--;
	}
}

void	swap_without_print(struct s_stack *stack)
{
	int		last;
	int		next;

	last = pop(stack);
	next = pop(stack);
	push(stack, last);
	push(stack, next);
}

void	rotate_without_print(struct s_stack *stack)
{
	int	next;
	int	index;
	int	temp;

	index = 1;
	next = stack->stack[0];
	stack->stack[0] = stack->stack[stack->index];
	while (index <= stack->index)
	{
		temp = stack->stack[index];
		stack->stack[index] = next;
		if (index < stack->index)
			next = temp;
		index++;
	}
}
