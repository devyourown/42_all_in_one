/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:43:35 by hyojulee          #+#    #+#             */
/*   Updated: 2022/04/23 21:33:26 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern  int	g_permu[24][4];
extern  int	g_permu_index;
extern  int	g_board[4][4];

void	swap(int *a, int *b)
{
	int		temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}

void	put_permu_to_board(int	row, int permu_index)
{
	int		index;

	index = 0;
	while (index < 4)
	{
		g_board[row][index] = g_permu[permu_index][index];
		index++;
	}
}

/*void	permutation(int data[], int depth)
{
	int	index;

	index = 0;
	if (depth == 4)
	{
		while (index < 4)
		{
			g_permu[g_permu_index][index] = data[index];
			g_permu_index++;
			index++;
		}
		return ;
	}
	index = depth;
	while (depth < 4)
	{
		swap(&data[depth], &data[index]);
		permutation(data, depth + 1);
		swap(&data[depth], &data[index]);
		depth++;
	}
}*/

void permutation(int idx, int *arr ,int *visited)
{
	if (idx == 4)
	{
		for (int i=0;i<4;i++)
		{
			g_permu[g_permu_index][i] = arr[i];
		}
		g_permu_index++;
	}
	for(int i=1;i <= 4;i++)
	{
		if (!visited[i])
		{
			arr[idx] = i;
			visited[i] = 1;
			permutation(idx+1, arr, visited);
			visited[i] = 0;
		}
	}
}
