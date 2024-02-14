/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 23:09:45 by marhakob          #+#    #+#             */
/*   Updated: 2022/06/22 01:23:29 by marhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_ptr(unsigned long long p)
{
	int	len;

	len = 2;
	write(1, "0x", 2);
	if (p == 0)
	{
		++len;
		write(1, "0", 1);
	}
	else
	{
		ft_putptr(p);
		len = len + ft_ptrlen(p);
	}
	return (len);
}
