/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_impl2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:53:25 by hyojulee          #+#    #+#             */
/*   Updated: 2022/11/11 15:00:35 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ra(t_pushswap *answer)
{
	rotate(answer->stacks[A_CASE]);
	write(1, "ra\n", 3);
}

void	rb(t_pushswap *answer)
{
	rotate(answer->stacks[B_CASE]);
	write(1, "rb\n", 3);
}

void	rr(t_pushswap *answer)
{
	rotate(answer->stacks[A_CASE]);
	rotate(answer->stacks[B_CASE]);
	write(1, "rr\n", 3);
}

void	rra(t_pushswap *answer)
{
	reverse_rotate(answer->stacks[A_CASE]);
	write(1, "rra\n", 4);
}

void	rrb(t_pushswap *answer)
{
	reverse_rotate(answer->stacks[B_CASE]);
	write(1, "rrb\n", 4);
}
