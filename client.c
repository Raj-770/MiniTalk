/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:02:51 by rpambhar          #+#    #+#             */
/*   Updated: 2023/11/20 15:27:13 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "ft_printf/ft_printf.h"

char	*char_to_binary(char c);
void	transmit_signal(char *data, pid_t pid);

int	main(int argc, char **argv)
{
	int		i;
	pid_t	pid;

	i = 0;
	if (argc != 3 || ft_strlen(argv[2]) == 0)
		return (1);
	if (ft_strlen(&argv[1][i]) == 0)
		return (1);
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i]))
			return (1);
		++i;
	}
	pid = ft_atoi(argv[1]);
	transmit_signal(argv[2], pid);
	return (0);
}

void	transmit_signal(char *data, pid_t pid)
{
	char	*char_in_binary;
	size_t	i;
	int		j;

	i = 0;
	while (i < ft_strlen(data))
	{
		j = 0;
		char_in_binary = char_to_binary(data[i]);
		while (j < 8)
		{
			if (char_in_binary[j] == '0')
				kill(pid, SIGUSR1);
			if (char_in_binary[j] == '1')
				kill(pid, SIGUSR2);
			usleep(50);
			j++;
		}
		++i;
		free(char_in_binary);
	}
}

char	*char_to_binary(char c)
{
	int		n;
	int		i;
	char	*ret;

	n = (int) c;
	ret = malloc(8 * sizeof(char));
	i = 7;
	ft_memset(ret, '0', 8);
	while (n != 0)
	{
		if (n % 2 != 0)
			ret[i] = '0' + 1;
		n = n / 2;
		--i;
	}
	return (ret);
}
