/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:57:23 by hyojulee          #+#    #+#             */
/*   Updated: 2022/04/20 19:20:26 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_lowercase(char c)
{
	if (c >= 97 && c <= 122)
		return (1);
	else
		return (0);
}

char	get_upcase_from_lowercase(char c)
{
	return (c - 32);
}

char	*ft_strupcase(char *str)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
	{
		if (is_lowercase(str[index]))
			str[index] = get_upcase_from_lowercase(str[index]);
		index++;
	}
	return (str);
}
