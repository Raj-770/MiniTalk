/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:50:09 by rpambhar          #+#    #+#             */
/*   Updated: 2023/11/18 12:27:13 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse(const char *input, va_list args, t_variables *var)
{
	while (input[var->i])
	{
		if (input[var->i] == '%' && input[var->i + 1])
		{
			var->i++;
			ft_format(input[var->i], args, var);
		}
		else
			putchar(input[var->i], 1, var);
		var->i++;
		if (var->error < 0)
			return (-1);
	}
	return (0);
}
