/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:10:00 by hyojulee          #+#    #+#             */
/*   Updated: 2022/12/16 20:26:15 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_H
# define HELPER_H

# include <stdlib.h>

void		*ft_memmove(void *dest, void *source, int num);
int			ft_strlen(const char *str);
char		*ft_strjoin_with_space(char *s1, char *s2);
int			get_size_of(char **str);
char		*ft_strdup(char *src);
char		**ft_split(char const *s, char c);
long long	ft_atol(const char *str);
int			ft_atoi(const char *str);

#endif
