/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:03:50 by hyojulee          #+#    #+#             */
/*   Updated: 2022/05/04 21:47:04 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	get_length(char *str)
{
	int		index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char	*ft_strdup(char *src)
{
	int		length;
	int		index;
	char	*dest;

	index = 0;
	length = get_length(src);
	dest = malloc(sizeof(char) * (length + 1));
	if (dest == NULL)
		return (NULL);
	while (src[index])
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = 0;
	return (dest);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int				index;
	t_stock_str		*stocks;

	index = 0;
	stocks = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (stocks == NULL)
		return (NULL);
	while (index < ac)
	{
		stocks[index].size = get_length(av[index]);
		stocks[index].str = av[index];
		stocks[index].copy = ft_strdup(av[index]);
		index++;
	}
	stocks[index].str = 0;
	return (stocks);
}
