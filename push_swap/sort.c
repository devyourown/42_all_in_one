/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:56:18 by hyojulee          #+#    #+#             */
/*   Updated: 2022/11/23 16:18:36 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "compare.h"
#include "operations.h"

int	*get_sorted_arr(int *arr, int size)
{
	quicksort(arr, 0, size - 1);
	return (arr);
}

void	swap_int(int *a, int *b)
{
	int		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	quicksort(int arr[], int left, int right)
{
	int		pivot_index;

	if (left < right)
	{
		pivot_index = partition(arr, left, right);
		if (left < pivot_index - 1)
			quicksort(arr, left, pivot_index - 1);
		if (pivot_index + 1 < right)
			quicksort(arr, pivot_index + 1, right);
	}
}

int	partition(int arr[], int left, int right)
{
	int		pivot;
	int		low;
	int		high;

	pivot = arr[left];
	low = left + 1;
	high = right;
	while (low <= high)
	{
		while (arr[low] < pivot && low <= right)
			low++;
		while (arr[high] > pivot && left <= high)
			high--;
		if (low <= high)
		{
			swap_int(&arr[low], &arr[high]);
			low++;
			high--;
		}
	}
	swap_int(&arr[left], &arr[high]);
	return (high);
}
