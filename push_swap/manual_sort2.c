/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_sort2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:39:04 by hyojulee          #+#    #+#             */
/*   Updated: 2022/11/11 21:50:42 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "compare.h"
#include "operations.h"

void	manual_sort_with_5(t_pushswap *answer)
{
	int	pivot;
	int	count;

	pivot = get_pivot(answer, A_CASE);
	count = 0;
	while (count < 2)
	{
		if (pivot > answer->stacks[A_CASE]
			->arr[answer->stacks[A_CASE]->current_index])
		{
			count++;
			pb(answer);
		}
		else
			rra(answer);
	}
	manual_sort_with_3(answer);
	answer->which_case = B_CASE;
	manual_sort_with_2(answer);
	pa(answer);
	pa(answer);
}

void	manual_sort_with_3(t_pushswap *answer)
{
	t_stack		*a;

	a = answer->stacks[A_CASE];
	if (is_highlowmid(a->arr[0], a->arr[1], a->arr[2]))
		sa(answer);
	else if (is_lowmidhigh(a->arr[0], a->arr[1], a->arr[2]))
	{
		ra(answer);
		sa(answer);
	}
	else if (is_lowhighmid(a->arr[0], a->arr[1], a->arr[2]))
		rra(answer);
	else if (is_midhighlow(a->arr[0], a->arr[1], a->arr[2]))
	{
		rra(answer);
		sa(answer);
	}
	else if (is_midlowhigh(a->arr[0], a->arr[1], a->arr[2]))
		ra(answer);
}
