/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:57:21 by hyojulee          #+#    #+#             */
/*   Updated: 2022/11/11 19:24:14 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATOR_H
# define VALIDATOR_H

typedef enum boolean
{
	false,
	true
}	t_boolean;

t_boolean	is_integer(const char *str);
t_boolean	has_duplicates(int *arr, int length);
t_boolean	validate_args(char **argv, int argc);
int			ft_strlen(const char *str);
long long	ft_atol(const char *str);
int			ft_atoi(const char *str);

#endif
