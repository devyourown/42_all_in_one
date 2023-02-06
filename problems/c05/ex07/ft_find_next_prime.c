/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 21:50:26 by hyojulee          #+#    #+#             */
/*   Updated: 2022/04/26 15:53:01 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long long		root;

	root = 1;
	while (root * root <= nb)
	{
		if (root * root == nb)
			return (root);
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

int	ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb))
		return (nb);
	while (1)
	{
		if (ft_is_prime(++nb))
			return (nb);
	}
}
