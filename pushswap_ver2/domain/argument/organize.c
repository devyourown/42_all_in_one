/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:18:27 by hyojulee          #+#    #+#             */
/*   Updated: 2022/12/16 20:24:41 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../helper/helper.h"

char	**organize_argument(int argc, char **argv)
{
	char	*joined;
	int		index;

	index = 1;
	joined = argv[1];
	while (index <= argc - 1)
	{
		joined = ft_strjoin_with_space(joined, argv[index + 1]);
		index++;
	}
	return (ft_split(joined, ' '));
}
