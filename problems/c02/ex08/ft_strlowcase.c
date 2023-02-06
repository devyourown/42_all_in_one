/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:13:30 by hyojulee          #+#    #+#             */
/*   Updated: 2022/04/21 13:39:30 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_uppercase(char c)
{
	if (c >= 65 && c <= 90)
		return (1);
	else
		return (0);
}

char	get_lowercase_from_upcase(char c)
{
	return (c + 32);
}

char	*ft_strlowcase(char *str)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
	{
		if (is_uppercase(str[index]))
			str[index] = get_lowercase_from_upcase(str[index]);
		index++;
	}
	return (str);
}
