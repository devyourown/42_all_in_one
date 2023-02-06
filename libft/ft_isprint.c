/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:30:05 by hyojulee          #+#    #+#             */
/*   Updated: 2022/09/02 11:08:55 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int num)
{
	if (num >= 32 && num <= 126)
		return (1);
	return (0);
}
