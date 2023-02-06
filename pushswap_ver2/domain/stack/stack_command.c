/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:31:56 by hyojulee          #+#    #+#             */
/*   Updated: 2022/12/20 17:42:08 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

struct s_stack
{
	int		*stack;
	int		index;
	char	stack_name;
};

void	swap(struct s_stack *stack)
{
	int		last;
	int		next;

	last = pop(stack);
	next = pop(stack);
	push(stack, last);
	push(stack, next);
	write(1, "s", 1);
	write(1, &stack->stack_name, 1);
	write(1, "\n", 1);
}

void	swap_all(struct s_stack *a, struct s_stack *b)
{
	swap_without_print(a);
	swap_without_print(b);
	write(1, "ss\n", 3);
}

void	push_to_from(struct s_stack *to, struct s_stack *from)
{
	push(to, pop(from));
	write(1, "p", 1);
	write(1, &to->stack_name, 1);
	write(1, "\n", 1);
}

void	rotate(struct s_stack *stack)
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
	write(1, "r", 1);
	write(1, &stack->stack_name, 1);
	write(1, "\n", 1);
}

void	rotate_all(struct s_stack *a, struct s_stack *b)
{
	rotate_without_print(a);
	rotate_without_print(b);
	write(1, "rr\n", 3);
}
