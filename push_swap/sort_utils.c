/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:17:34 by hyojulee          #+#    #+#             */
/*   Updated: 2022/11/11 21:43:20 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "operations.h"

int	get_pivot(t_pushswap *answer, int which_case)
{
	int		*sorted;
	int		size;
	int		result;

	if (answer->stacks[which_case]->current_index <= 2)
		return (0);
	size = answer->stacks[which_case]->current_index + 1;
	sorted = (int *)malloc(sizeof(int) * size);
	if (sorted == NULL)
		exit(1);
	ft_memmove(sorted, answer->stacks[which_case]->arr, size);
	quicksort(sorted, 0, size - 1);
	result = sorted[size - 3];
	free(sorted);
	return (result);
}

void	send_b_left(t_pushswap *answer)
{
	while (answer->stacks[B_CASE]->current_index >= 0)
		pa(answer);
}
