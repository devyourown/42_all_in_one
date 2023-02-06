/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:22:17 by hyojulee          #+#    #+#             */
/*   Updated: 2022/11/10 20:04:51 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPARE_H
# define COMPARE_H

# include "validator.h"

t_boolean	is_lowhighmid(int a, int b, int c);
t_boolean	is_midhighlow(int a, int b, int c);
t_boolean	is_midlowhigh(int a, int b, int c);
t_boolean	is_highlowmid(int a, int b, int c);
t_boolean	is_lowmidhigh(int a, int b, int c);
t_boolean	is_highmidlow(int a, int b, int c);

#endif
