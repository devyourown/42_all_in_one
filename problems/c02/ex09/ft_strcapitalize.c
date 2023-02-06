/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:15:12 by hyojulee          #+#    #+#             */
/*   Updated: 2022/04/21 16:05:14 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	is_alphanum(char c);
int	is_num(char c);
int	is_uppercase(char c);
int	is_lowercase(char c);

int	is_alphanum(char c)
{
	if (is_uppercase(c))
		return (1);
	else if (is_lowercase(c))
		return (1);
	else if (is_num(c))
		return (1);
	return (0);
}

int	is_num(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	is_uppercase(char c)
{
	if (c >= 65 && c <= 90)
		return (1);
	return (0);
}

int	is_lowercase(char c)
{
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int		index;
	int		should_be_upcase;

	index = 0;
	should_be_upcase = 1;
	while (str[index])
	{
		if (!is_alphanum(str[index]))
			should_be_upcase = 1;
		else if (should_be_upcase && is_lowercase(str[index]))
		{
			should_be_upcase = 0;
			str[index] -= 32;
		}
		else if (!should_be_upcase && is_uppercase(str[index]))
		{
			str[index] += 32;
			should_be_upcase = 0;
		}
		else
			should_be_upcase = 0;
		index++;
	}
	return (str);
}
