/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:04:26 by hyojulee          #+#    #+#             */
/*   Updated: 2022/11/11 19:43:10 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compare.h"

t_boolean	is_highmidlow(int a, int b, int c)
{
	if (a > b && b > c && a > c)
		return (true);
	return (false);
}
