/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojulee <hyojulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:26:11 by hyojulee          #+#    #+#             */
/*   Updated: 2022/11/08 16:03:05 by hyojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

size_t	ft_strlen(const char *str);
char	*ft_itoa(int n);
void	print_pid(void);
int		handle_signal(void);
void	handler(int sig);

#endif
