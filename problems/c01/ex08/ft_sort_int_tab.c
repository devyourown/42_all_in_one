/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:28:52 by hyojulee          #+#    #+#             */
/*   Updated: 2022/05/01 14:14:50 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		partition(int arr[], int left, int right);

void	swap(int *a, int *b)
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
			swap(&arr[low], &arr[high]);
			low++;
			high--;
		}
	}
	swap(&arr[left], &arr[high]);
	return (high);
}

void	ft_sort_int_tab(int *tab, int size)
{
	quicksort(tab, 0, size - 1);
}
