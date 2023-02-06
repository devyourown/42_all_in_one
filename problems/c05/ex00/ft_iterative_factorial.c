/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 19:23:27 by hyojulee          #+#    #+#             */
/*   Updated: 2022/04/26 11:00:05 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int		index;
	int		result;

	index = 1;
	result = 1;
	if (nb < 0)
		return (0);
	while (index <= nb)
	{
		result *= index;
		index++;
	}
	return (result);
}
