/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:22:11 by hyojulee          #+#    #+#             */
/*   Updated: 2022/11/10 17:17:42 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compare.h"

t_boolean	is_lowhighmid(int a, int b, int c)
{
	if (a < b && b > c && a < c)
		return (true);
	return (false);
}

t_boolean	is_midhighlow(int a, int b, int c)
{
	if (a < b && b > c && a > c)
		return (true);
	return (false);
}

t_boolean	is_midlowhigh(int a, int b, int c)
{
	if (a > b && b < c && a < c)
		return (true);
	return (false);
}

t_boolean	is_highlowmid(int a, int b, int c)
{
	if (a > b && b < c && a > c)
		return (true);
	return (false);
}

t_boolean	is_lowmidhigh(int a, int b, int c)
{
	if (a < b && b < c && a < c)
		return (true);
	return (false);
}
