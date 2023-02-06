/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 21:18:49 by hyojulee          #+#    #+#             */
/*   Updated: 2022/09/13 15:29:57 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int				ft_printf(const char *str, ...);
char			*ft_itoa(int n);
char			*ft_uitoa(unsigned int n);
size_t			ft_strlen(const char *str);

int				print_va(char conversion, va_list ap);
int				print_number(va_list ap);
int				print_str(va_list ap);
int				print_character(va_list ap);
int				print_void(va_list ap, char *hex);
int				print_unumber(va_list ap);
int				print_hexnumber(va_list ap, char *hex);
int				print_percent(void);
int				print_reverse(char *str, int length);

#endif
