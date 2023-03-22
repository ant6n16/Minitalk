/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:53:36 by antdelga          #+#    #+#             */
/*   Updated: 2023/03/22 19:32:39 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include "../libft/libft.h"

void	manejador_sig(int signum, siginfo_t *info, void *context);
void	manejador_sig_bonus(int signum, siginfo_t *info, void *context);
void	manejador_sig_client(int signum);
void	send_message(int pid, char *str);
void	send_null(int pid);

#endif
