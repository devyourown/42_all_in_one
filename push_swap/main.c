/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:05:08 by hyojulee          #+#    #+#             */
/*   Updated: 2022/12/16 18:10:10 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "sort.h"

t_boolean	is_sorted(t_pushswap *answer)
{
	int		index_start;
	int		index_end;

	index_start = 0;
	index_end = answer->size;
	while (index_start <= answer->size)
	{
		if (answer->sorted_arr[index_start]
			!= answer->stacks[A_CASE]->arr[index_end])
			return (false);
		index_start++;
		index_end--;
	}
	return (true);
}

void	init_answer(t_pushswap *answer, int *input)
{
	answer->stacks[A_CASE] = init_stack_with_arr(input, answer->size);
	answer->stacks[B_CASE] = create_empty_stack(answer->size);
	answer->sorted_arr = get_sorted_arr(input, answer->size);
	answer->which_case = A_CASE;
	answer->pivot_stack = create_empty_stack(answer->size);
}

int	main(int argc, char **argv)
{
	int			*input_int;
	t_pushswap	*answer;
	char		**input;

	if (argc == 1)
		return (1);
	answer = (t_pushswap *)malloc(sizeof(t_pushswap));
	input = init_input(argc, argv);
	answer->size = count_number(input);
	if (!validate_args(input, answer->size))
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	input_int = convert_to_int_array(input, answer->size);
	init_answer(answer, input_int);
	if (is_sorted(answer))
		exit(0);
	sort(answer);
	exit(0);
	return (0);
}
