/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 21:38:15 by hyojulee          #+#    #+#             */
/*   Updated: 2022/04/27 21:13:42 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long long		root;

	root = 1;
	while (root * root <= nb)
	{
		if (root * root == nb)
			return ((int)(root));
		root++;
	}
	return (root - 1);
}

int	ft_is_prime(int nb)
{
	int		index;

	if (nb == 2)
		return (1);
	if (nb <= 1)
		return (0);
	index = 2;
	while (index <= ft_sqrt(nb))
	{
		if (nb % index == 0)
			return (0);
		index++;
	}
	return (1);
}
