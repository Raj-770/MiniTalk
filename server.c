/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:58:58 by rpambhar          #+#    #+#             */
/*   Updated: 2023/11/28 19:54:58 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "ft_printf/ft_printf.h"

void	handle_signal(int signal_value)
{
	static int	binary_char = 0;
	static int	i;
	char		c;

	if (signal_value == SIGUSR1)
	{
		binary_char = binary_char << 1;
		i++;
	}
	if (signal_value == SIGUSR2)
	{
		binary_char = (binary_char << 1) | 1;
		i++;
	}
	if (i == 8)
	{
		c = (char)binary_char;
		write(1, &c, 1);
		binary_char = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sig_act;

	ft_printf("%s\t __  __ _      _ _____     _ _\n", "\033[0;33m");
	ft_printf("\t|  \\/  (_)_ _ (_)_   _|_ _| | |__\n");
	ft_printf("\t| |\\/| | | ' \\| | | |/ _` | | / /\n");
	ft_printf("\t|_|  |_|_|_||_|_| |_|\\__,_|_|_\\_\\\n\n");
	ft_printf("⊱ ───────────────── {.⋅ ✯ ⋅.} ───────────────── ⊰\n\n");
	ft_printf("%sPID: %d\n\n", "\033[0m", getpid());
	sig_act.sa_flags = 0;
	sig_act.sa_handler = handle_signal;
	sigemptyset(&sig_act.sa_mask);
	if (sigaction(SIGUSR1, &sig_act, NULL) == -1)
		return (-1);
	else if (sigaction(SIGUSR2, &sig_act, NULL) == -1)
		return (-1);
	while (1)
	{
		pause();
	}
	return (0);
}
