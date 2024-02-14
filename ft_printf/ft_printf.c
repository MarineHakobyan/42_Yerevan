/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 23:09:45 by marhakob          #+#    #+#             */
/*   Updated: 2022/06/22 01:23:29 by marhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf(const char *print, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = -1;
	len = 0;
	va_start(args, print);
	while (print[++i])
	{
		if (print[i] == '%')
		{
			++i;
			len += ft_type(args, print[i], &print[i]);
		}
		else
			len += ft_putchar_fd(print[i], 1);
	}
	va_end(args);
	return (len);
}
