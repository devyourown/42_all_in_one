/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:01:00 by hyojulee          #+#    #+#             */
/*   Updated: 2022/11/11 17:36:15 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_H
# define CONVERT_H

int		*convert_to_int_array(char **argv, int argc);
int		count_number(char **str);
char	**init_input(int argc, char **argv);
char	**ft_split(char const *s, char c);
char	*ft_strdup(char *src);
char	*ft_strjoin_with_space(char *s1, char *s2);
void	*ft_memmove(void *dest, void *source, int num);

#endif
