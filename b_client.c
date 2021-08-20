/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_client.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 00:42:01 by abambi            #+#    #+#             */
/*   Updated: 2021/07/08 22:09:28 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	struct sigaction	sig2;
	int					error_flag;
	int					len;

	ft_memset(&sig2, 0, sizeof(sig2));
	sigemptyset(&sig2.sa_mask);
	sig2.sa_sigaction = server_answered;
	sig2.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig2, NULL);
	sigaction(SIGUSR2, &sig2, NULL);
	error_flag = 0;
	if (ac == 3)
	{
		len = ft_strlen(av[2]) + 1;
		while (len-- > 0 && error_flag == 0)
			error_flag = push_char(ft_atoi(av[1]), *av[2]++);
		if (error_flag == -1)
			write(2, "Client: Error in transfer\n", 26);
	}
	else
		write(2, "Wrong args.\n Write 2 args: server_PID and the_message\n", 54);
	return (0);
}

int	push_char(pid_t pid, char c)
{
	int		bit_move;
	int		error_flag;

	bit_move = -1;
	error_flag = 0;
	while (++bit_move < 8)
	{
		if ((c >> bit_move) & 1)
			error_flag = kill(pid, SIGUSR2);
		else
			error_flag = kill(pid, SIGUSR1);
		if (error_flag == -1)
			break ;
		usleep(30000);
	}
	return (error_flag);
}

void	server_answered(int signal_num, siginfo_t *info, void *old_info)
{
	(void)old_info;
	(void)info;
	if (signal_num == SIGUSR2)
		write(1, "Message is printed\n", 19);
	else
		(void)signal_num;
}
