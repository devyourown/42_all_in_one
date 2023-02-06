/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:11:12 by hyojulee          #+#    #+#             */
/*   Updated: 2022/09/27 14:45:18 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

size_t	ft_strlen(const char *str)
{
	size_t		index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}
