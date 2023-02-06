/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:54:48 by hyojulee          #+#    #+#             */
/*   Updated: 2022/12/16 22:00:43 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "./domain/stack/stack.h"
#include "./domain/argument/argument.h"
#include "./domain/helper/helper.h"

int	main(int argc, char **argv)
{
	struct s_stack	*a;
	char			**organized;

	if (argc == 1)
		return (0);
	organized = organize_argument(argc, argv);
	if (!validate_args(get_size_of(organized), organized))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	a = make_stack(make_int_array(argc, argv),
			get_size_of(organized), 'a');
	if (is_sorted(a))
		exit(0);
	//sort(a);
	exit(0);
}
