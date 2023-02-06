/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:21:17 by hyojulee          #+#    #+#             */
/*   Updated: 2022/12/20 17:41:29 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H

# include "../helper/constants.h"
# include <unistd.h>

struct	s_stack;

struct s_stack	*make_stack(int *arr, int size, char name);
int				get_size(struct s_stack *stack);
int				pop(struct s_stack *stack);
void			push(struct s_stack *stack, int value);
t_boolean		is_sorted(struct s_stack *stack);

t_boolean		is_lowhighmid(struct s_stack *stack);
t_boolean		is_midhighlow(struct s_stack *stack);
t_boolean		is_midlowhigh(struct s_stack *stack);
t_boolean		is_highlowmid(struct s_stack *stack);
t_boolean		is_lowmidhigh(struct s_stack *stack);

void			swap(struct s_stack *stack);
void			swap_without_print(struct s_stack *stack);
void			swap_all(struct s_stack *a, struct s_stack *b);
void			push_to_from(struct s_stack *to, struct s_stack *from);
void			rotate(struct s_stack *stack);
void			rotate_without_print(struct s_stack *stack);
void			rotate_all(struct s_stack *a, struct s_stack *b);
void			reverse_rotate(struct s_stack *stack);
void			reverse_rotate_without_print(struct s_stack *stack);
void			reverse_rotate_all(struct s_stack *a, struct s_stack *b);

#endif
