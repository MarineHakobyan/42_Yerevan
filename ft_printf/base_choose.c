/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_choose.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 23:09:45 by marhakob          #+#    #+#             */
/*   Updated: 2022/06/22 01:23:29 by marhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	base_choose(unsigned int nbr, char c)
{
	if (c == 'x')
		return (ft_putitoa_base(nbr, "0123456789abcdef"));
	return (ft_putitoa_base(nbr, "0123456789ABCDEF"));
}
