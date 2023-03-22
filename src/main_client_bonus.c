/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:52:47 by antdelga          #+#    #+#             */
/*   Updated: 2023/03/22 14:05:06 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

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

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Error. The correct input is like: ./client PID message\n");
		return (0);
	}
	send_message(ft_atoi(argv[1]), argv[2]);
	send_message(ft_atoi(argv[1]), "\n\0");
	return (0);
}
