/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 19:44:36 by hyojulee          #+#    #+#             */
/*   Updated: 2022/05/04 11:23:25 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	check_base(char *base);
int	get_strlen(char *str);

char	*ft_putnum(char *result, long long nbr, char *base, int size)
{
	int		base_length;
	int		end;

	if (nbr < 0)
	{
		result[0] = '-';
		end = 1;
		nbr = -nbr;
	}
	else
		end = 0;
	result[size--] = '\0';
	base_length = get_strlen(base);
	while (size >= end)
	{
		result[size--] = base[nbr % base_length];
		nbr /= base_length;
	}
	return (result);
}

char	*ft_itoa(long	long num, char *base)
{
	int				base_length;
	char			*result;
	int				size;
	long long		nbr;

	nbr = num;
	base_length = get_strlen(base);
	result = (char *)malloc(sizeof(char) * 34);
	if (!result)
		return (NULL);
	size = 1;
	if (nbr < 0)
	{
		nbr = -nbr;
		size++;
	}
	while (nbr >= base_length)
	{
		nbr /= base_length;
		size++;
	}
	ft_putnum(result, num, base, size);
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		result;

	if (check_base(base_from) * check_base(base_to) == 0)
		return (NULL);
	result = ft_atoi_base(nbr, base_from);
	return (ft_itoa(result, base_to));
}
