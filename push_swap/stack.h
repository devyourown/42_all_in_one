/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:59:04 by hyojulee          #+#    #+#             */
/*   Updated: 2022/11/09 16:15:38 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_stack
{
	int	*arr;
	int	current_index;
}	t_stack;

int		pop(t_stack *stack);
int		peek(t_stack *stack);
void	push(t_stack *stack, int value);
t_stack	*init_stack_with_arr(int *arr, int size);
t_stack	*create_empty_stack(int size);

#endif
