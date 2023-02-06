/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:16:07 by hyojulee          #+#    #+#             */
/*   Updated: 2022/04/27 17:37:33 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_strlen(char *str)
{
	int		index;

	index = 0;
	while (*str)
	{
		index++;
		str++;
	}
	return (index);
}

int	check_base(char *base)
{
	char	word[256];
	int		index;

	index = 0;
	while (index < 256)
		word[index++] = 0;
	if (get_strlen(base) <= 1)
		return (0);
	while (*base)
	{
		if ((9 <= *base && *base <= 13) || *base == 32)
			return (0);
		if (*base == '+' || *base == '-')
			return (0);
		if (word[(int)(*base)] != 0)
			return (0);
		word[(int)(*base)]++;
		base++;
	}
	return (1);
}

int	get_cardinal_num(char current, char *base)
{
	int		index;

	index = 0;
	while (base[index])
	{
		if (current == base[index])
			return (index);
		index++;
	}
	return (-1);
}

int	pass_to_value(char *str, int index, int *minus)
{
	*minus = 1;
	while ((9 <= str[index] && str[index] <= 13) || str[index] == 32)
		index++;
	while (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			*minus *= -1;
		index++;
	}
	return (index);
}

int	ft_atoi_base(char *str, char *base)
{
	int		index;
	int		minus;
	int		base_notation;
	int		result;
	int		cardinal_num;

	result = 0;
	base_notation = get_strlen(base);
	if (!check_base(base))
		return (0);
	index = pass_to_value(str, 0, &minus);
	while (str[index])
	{
		cardinal_num = get_cardinal_num(str[index], base);
		if (cardinal_num == -1)
			return (result * minus);
		result = result * base_notation + cardinal_num;
		index++;
	}
	return (result * minus);
}
