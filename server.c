/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:58:58 by rpambhar          #+#    #+#             */
/*   Updated: 2023/11/18 12:29:23 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "ft_printf/ft_printf.h"


int	main(void)
{
	pid_t				pid;
	int					integer_pid;

	pid = getpid();
	integer_pid = (int) pid;
	ft_printf("%d", integer_pid);
	return (0);
}