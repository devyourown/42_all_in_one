/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 13:44:02 by hyojulee          #+#    #+#             */
/*   Updated: 2022/04/20 17:29:07 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int		div;
	int		mod;	

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}
