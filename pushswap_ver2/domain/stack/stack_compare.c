/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_compare.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:17:48 by hyojulee          #+#    #+#             */
/*   Updated: 2022/12/16 21:55:20 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

struct s_stack {
	int		*stack;
	int		index;
	char	stack_name;
};

t_boolean	is_lowhighmid(struct s_stack *stack)
{
	int		first;
	int		second;
	int		third;

	first = stack->stack[0];
	second = stack->stack[1];
	third = stack->stack[2];
	if (first < second && second > third && first < third)
		return (true);
	return (false);
}

t_boolean	is_midhighlow(struct s_stack *stack)
{
	int		first;
	int		second;
	int		third;

	first = stack->stack[0];
	second = stack->stack[1];
	third = stack->stack[2];
	if (first < second && second > third && first > third)
		return (true);
	return (false);
}

t_boolean	is_midlowhigh(struct s_stack *stack)
{
	int		first;
	int		second;
	int		third;

	first = stack->stack[0];
	second = stack->stack[1];
	third = stack->stack[2];
	if (first > second && second < third && first < third)
		return (true);
	return (false);
}

t_boolean	is_highlowmid(struct s_stack *stack)
{
	int		first;
	int		second;
	int		third;

	first = stack->stack[0];
	second = stack->stack[1];
	third = stack->stack[2];
	if (first > second && second < third && first > third)
		return (true);
	return (false);
}

t_boolean	is_lowmidhigh(struct s_stack *stack)
{
	int		first;
	int		second;
	int		third;

	first = stack->stack[0];
	second = stack->stack[1];
	third = stack->stack[2];
	if (first < second && second < third && first < third)
		return (true);
	return (false);
}
