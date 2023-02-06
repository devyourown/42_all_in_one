/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:55:07 by hyojulee          #+#    #+#             */
/*   Updated: 2022/11/11 15:01:49 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "stack.h"
# include "pushswap.h"

void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	push_from_another_stack(t_stack *stack, t_stack *another);

void	sa(t_pushswap *answer);
void	sb(t_pushswap *answer);
void	ss(t_pushswap *answer);
void	pa(t_pushswap *answer);
void	pb(t_pushswap *answer);
void	ra(t_pushswap *answer);
void	rb(t_pushswap *answer);
void	rr(t_pushswap *answer);
void	rra(t_pushswap *answer);
void	rrb(t_pushswap *answer);
void	rrr(t_pushswap *answer);

#endif
