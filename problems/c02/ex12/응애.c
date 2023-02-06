/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:03:18 by hyojulee          #+#    #+#             */
/*   Updated: 2022/05/05 15:27:41 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_memory_address(long long address);
void	print_string_to_hex(char *str, int size);
void	print_hex(unsigned char c, int should_be_spaced, int is_ended);
void	print_string(char *str, int size);
void	*ft_print_memory(void *addr, unsigned int size);

void	print_string(char *str, int size)
{
	int		index;

	index = 0;
	while (index < 16)
	{
		if (index >= size)
			return ;
		else if (str[index] >= 32 && str[index] <= 126)
			write(1, &str[index], 1);
		else
			write(1, ".", 1);
		index++;
	}
}

void	print_memory_address(long long address)
{
	char		result[17];
	int			index;

	index = 15;
	result[16] = '\0';
	while (index >= 0)
	{
		if (address % 16 >= 10)
			result[index--] = address % 16 + 87;
		else
			result[index--] = address % 16 + 48;
		address /= 16;
	}
	write(1, result, 16);
	write(1, ": ", 2);
}

void	print_string_to_hex(char *str, int size)
{
	int		index;

	index = 0;
	while (index <= 15)
	{
		if (index >= size)
			print_hex(str[index], index % 2, 1);
		else
			print_hex(str[index], index % 2, 0);
		index++;
	}
}

void	print_hex(unsigned char c, int should_be_spaced, int is_ended)
{
	if (! is_ended)
	{
		write(1, &"0123456789abcdef"[c / 16], 1);
		write(1, &"0123456789abcdef"[c % 16], 1);
	}
	else
		write(1, "  ", 2);
	if (should_be_spaced)
		write(1, " ", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int		length;
	int		index;

	index = 0;
	length = size / 16;
	if (size % 16 > 0)
		length += 1;
	while (length > 0)
	{
		print_memory_address((long long)(addr + index));
		print_string_to_hex((addr + index), size - index);
		print_string(addr + index, size - index);
		write(1, "\n", 1);
		index += 16;
		length--;
	}
	return (addr);
}
#include <string.h>
#include <stdio.h>
int main(void)
{ char string[] =
"Bonjour les aminches\t\n\tc  est fou\ttout\tce qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n "
;
 string[90] = 32;
 ft_print_memory(string, 100);
// write(1, "\n", 1);
// char string2[77] = "salute ! i'm gunwoo ! what's up !";
// ft_print_memory(string2, sizeof(string2));
}
