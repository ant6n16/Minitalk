/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:52:47 by antdelga          #+#    #+#             */
/*   Updated: 2023/03/21 14:15:24 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	ManejadorSig(int signo, siginfo_t *info, void *context)
{


	(void) context;

}

int	main(void)
{
	struct		sigaction act;	// Manejador de señal
	sigset_t	sigset;

	sigemptyset(&sigset); 		 // Crea máscara vacía
	sigaddset(&sigset, SIGUSR1); // Añade la señal y la activa
	sigaddset(&sigset, SIGUSR2); // Añade la señal y la activa

	act.sa_sigaction = ManejadorSig; // Manejador de la señal
	act.sa_flags = SA_SIGINFO; // Modo extendido
	
	ft_printf("%d\n", getpid());
	while (1)
		pause();
	return (0);
}
