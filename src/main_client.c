/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:52:47 by antdelga          #+#    #+#             */
/*   Updated: 2023/03/21 20:55:50 by antdelga         ###   ########.fr       */
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
		pos = 8;
		while (pos-- > 0)
		{
			c = str[index] >> pos & 1;
			if (c == 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
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
	return (0);
}
