/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:05:33 by hyojulee          #+#    #+#             */
/*   Updated: 2022/11/13 21:36:49 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# include "validator.h"
# include "stack.h"
# include "convert.h"

# define A_CASE	0
# define B_CASE	1

typedef struct s_pushswap
{
	t_stack	*stacks[2];
	int		*sorted_arr;
	int		size;
	int		which_case;
	t_stack	*pivot_stack;
}	t_pushswap;

#endif
