/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_impl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:46:13 by hyojulee          #+#    #+#             */
/*   Updated: 2022/11/11 14:58:50 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	sa(t_pushswap *answer)
{
	swap(answer->stacks[A_CASE]);
	write(1, "sa\n", 3);
}

void	sb(t_pushswap *answer)
{
	swap(answer->stacks[B_CASE]);
	write(1, "sb\n", 3);
}

void	ss(t_pushswap *answer)
{
	swap(answer->stacks[A_CASE]);
	swap(answer->stacks[B_CASE]);
	write(1, "ss\n", 3);
}

void	pa(t_pushswap *answer)
{
	push_from_another_stack(answer->stacks[A_CASE], answer->stacks[B_CASE]);
	write(1, "pa\n", 3);
}

void	pb(t_pushswap *answer)
{
	push_from_another_stack(answer->stacks[B_CASE], answer->stacks[A_CASE]);
	write(1, "pb\n", 3);
}
