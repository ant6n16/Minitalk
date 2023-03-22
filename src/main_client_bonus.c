/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:52:47 by antdelga          #+#    #+#             */
/*   Updated: 2023/03/22 19:52:31 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	manejador_sig_client(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_printf("Message recived succesfully in server.\n");
		exit(0);
	}
}

void	send_message(int pid, char *str)
{
	int	index;
	int	pos;
	int	c;

	index = 0;
	while (str[index] != '\0')
	{
		pos = 0;
		while (pos != 8)
		{
			c = str[index] >> pos & 1;
			if (c == 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
			pos++;
		}
	index++;
	}
}

void	send_null(int pid)
{
	int	index;

	index = 0;
	while (index < 8)
	{
		kill(pid, SIGUSR1);
		usleep(100);
		index++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Error. The correct input is like: ./client PID message\n");
		return (0);
	}
	signal(SIGUSR1, manejador_sig_client);
	signal(SIGUSR2, manejador_sig_client);
	send_message(ft_atoi(argv[1]), argv[2]);
	send_message(ft_atoi(argv[1]), "\n\0");
	send_null(ft_atoi(argv[1]));
	return (0);
}
