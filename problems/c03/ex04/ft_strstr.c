/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:22:38 by hyojulee          #+#    #+#             */
/*   Updated: 2022/04/25 11:22:34 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		index;
	int		find_index;

	index = 0;
	if (!(*to_find))
		return (&str[index]);
	while (str[index])
	{
		if (str[index] == to_find[0])
		{
			find_index = 1;
			while (0 != to_find[find_index])
			{
				if (str[index + find_index] != to_find[find_index])
					break ;
				find_index++;
			}
			if (0 == to_find[find_index])
				return (&str[index]);
		}
		index++;
	}
	return (0);
}
