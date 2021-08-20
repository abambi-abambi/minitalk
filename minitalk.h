/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 13:55:48 by abambi            #+#    #+#             */
/*   Updated: 2021/07/08 22:05:58 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <sys/types.h>

int		ft_putnbr(int n);
size_t	ft_strlen(char *s);
void	*ft_memset(void *dest, int c, size_t len);
int		ft_atoi(const char *s);

/*
** server
*/

void	print_pid(void);
void	compose_bite(int signal_num, siginfo_t *info, void *old_info);
void	print_bite(int *bits, char *c, siginfo_t *info);

/*
** client
*/

int		push_char(pid_t pid, char c);
void	server_answered(int signal_num, siginfo_t *info, void *old_info);

#endif