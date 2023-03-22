/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:52:47 by antdelga          #+#    #+#             */
/*   Updated: 2023/03/22 19:31:48 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	manejador_sig_bonus(int signum, siginfo_t *info, void *context)
{
	static int				bit = 0;
	static unsigned char	c = 0;
	static pid_t			pid_check = 0;
	static int				count_zeros = 0;

	(void) context;
	pid_check = info->si_pid;
	if (signum == SIGUSR2)
		c = c + (1 << bit);
	else
		count_zeros++;
	if (count_zeros == 8)
		kill(pid_check, SIGUSR1);
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
		bit = 0;
		c = 0;
		count_zeros = 0;
	}
}

int	main(void)
{
	struct sigaction	act;

	ft_printf("PID bonus: %d\n", getpid());
	act.sa_sigaction = manejador_sig_bonus;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
