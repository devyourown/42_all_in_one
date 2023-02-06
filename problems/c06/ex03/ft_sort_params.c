/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:10:06 by hyojulee          #+#    #+#             */
/*   Updated: 2022/04/26 13:13:36 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		partition(char *arr[], int left, int right);

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	quicksort(char *arr[], int left, int right)
{
	int		pivot_index;

	if (left < right)
	{
		pivot_index = partition(arr, left, right);
		quicksort(arr, left, pivot_index - 1);
		quicksort(arr, pivot_index + 1, right);
	}
}

int	partition(char *arr[], int left, int right)
{
	int		pivot;
	int		low;
	int		high;

	pivot = left;
	low = left + 1;
	high = right;
	while (low <= high)
	{
		while (low <= right && (ft_strcmp(arr[low], arr[pivot]) < 0))
			low++;
		while (left <= high && (ft_strcmp(arr[high], arr[pivot]) > 0))
			high--;
		if (low <= high)
		{	
			swap(&arr[low], &arr[high]);
			low++;
			high--;
		}
	}
	swap(&arr[left], &arr[high]);
	return (high);
}

int	main(int argc, char *argv[])
{
	int		index;
	int		str_length;

	index = 1;
	quicksort(argv, 1, argc - 1);
	while (index < argc)
	{
		str_length = 0;
		while (argv[index][str_length])
			str_length++;
		write(1, argv[index], str_length);
		write(1, "\n", 1);
		index++;
	}
}
