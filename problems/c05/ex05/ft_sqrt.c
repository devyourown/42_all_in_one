/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 21:31:47 by hyojulee          #+#    #+#             */
/*   Updated: 2022/04/27 21:14:26 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long long		root;

	root = 1;
	while (root * root <= nb)
	{
		if (root * root == nb)
			return ((int)root);
		root++;
	}
	return (0);
}
