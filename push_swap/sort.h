/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:39:47 by hyojulee          #+#    #+#             */
/*   Updated: 2022/11/23 16:23:13 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "pushswap.h"

void	sort(t_pushswap *answer);
void	manual_sort(t_pushswap *answer);
void	manual_sort_a(t_pushswap *answer, int start, int end);
void	manual_sort_b(t_pushswap *answer, int start, int end);
void	manual_sort_with_2(t_pushswap *answer);
void	manual_sort_with_3(t_pushswap *answer);
void	manual_sort_with_5(t_pushswap *answer);

int		*get_sorted_arr(int *arr, int size);

void	a_send_lower_than_pivot(t_pushswap *answer, int left, int right);
void	b_send_bigger_than_pivot(t_pushswap *answer, int pivot);

int		partition(int arr[], int left, int right);
void	quicksort(int arr[], int left, int right);

int		get_pivot(t_pushswap *answer, int which_case);
void	*ft_memmove(void *dest, void *source, int num);
void	send_b_left(t_pushswap *answer);

void	split_a_three_part(t_pushswap *answer, int left, int right);
void	split_b_three_part(t_pushswap *answer, int left, int right);
void	send_to_b_stack(t_pushswap *answer, int pivot, int size);
void	send_to_a_stack(t_pushswap *answer, int pivot, int size);
void	manual_sort_in_a(t_pushswap *answer, int count);
void	send_to_a(t_pushswap *answer);

#endif
