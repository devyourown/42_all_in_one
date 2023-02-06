/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_impl3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:55:11 by hyojulee          #+#    #+#             */
/*   Updated: 2022/11/11 15:01:00 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	rrr(t_pushswap *answer)
{
	reverse_rotate(answer->stacks[A_CASE]);
	reverse_rotate(answer->stacks[B_CASE]);
	write(1, "rrr\n", 3);
}
