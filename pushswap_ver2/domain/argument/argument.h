/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:12:04 by hyojulee          #+#    #+#             */
/*   Updated: 2022/12/16 20:13:44 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGUMENT_H
# define ARGUMENT_H

# include "../helper/constants.h"

char		**organize_argument(int argc, char **argv);
t_boolean	validate_args(int argc, char **argv);
t_boolean	are_integers(int argc, char **argv);
t_boolean	is_integer(const char *str);
t_boolean	has_duplicates(int argc, char **argv);
int			*make_int_array(int argc, char **argv);

#endif
