/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:11:47 by hyojulee          #+#    #+#             */
/*   Updated: 2022/09/02 11:11:48 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int num)
{
	if (num >= 97 && num <= 122)
		return (num - 32);
	return (num);
}