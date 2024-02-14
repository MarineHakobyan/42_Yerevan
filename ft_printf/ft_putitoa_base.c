/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putitoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 23:09:45 by marhakob          #+#    #+#             */
/*   Updated: 2022/06/22 01:23:29 by marhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putitoa_base(unsigned int nbr, char *base)
{
	int	len;

	len = 0;
	if (nbr / 16 != 0)
		len += ft_putitoa_base(nbr / 16, base);
	if (nbr % 16 != 16)
		len += ft_putchar_fd(base[nbr % 16], 1);
	return (len);
}
