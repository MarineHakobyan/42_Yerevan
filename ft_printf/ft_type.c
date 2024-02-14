/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 23:09:45 by marhakob          #+#    #+#             */
/*   Updated: 2022/06/22 01:23:29 by marhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_type(va_list args, const char type, const char *print)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	if (print[i] == '+' || print[i] == '-' || print[i] == '#' || print[i] == '.'
		|| print[i] == ' ' || print[i] == '0')
		len += ft_printf_bonus(print[i++], args);
	if (type == 'c')
		len += ft_putchar_fd((char)va_arg(args, int), 1);
	else if (type == 's')
		len += ft_putstr_fd(va_arg(args, char *), 1);
	else if (type == 'd' || type == 'i')
		len += ft_putnbr_fd(va_arg(args, int), 1);
	else if (type == 'u')
		len += ft_putnbr_fd(va_arg(args, unsigned int), 1);
	else if (type == 'x' || type == 'X')
		len += base_choose(va_arg(args, unsigned int), type);
	else if (type == 'p')
		len += ft_ptr(va_arg(args, unsigned long long));
	else if (type == '%')
		len += ft_putchar_fd('%', 1);
	else
		len += ft_putchar_fd(type, 1);
	return (len);
}
