/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 23:09:45 by marhakob          #+#    #+#             */
/*   Updated: 2022/06/22 01:23:29 by marhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf_bonus(const char type, void *arg)
{
	if (type == '+')
	{
		if (*((int *)(arg)) < 0)
			return (write(1, "-", 1));
		else
			return (write(1, "+", 1));
	}
	else if (type == ' ')
	{
		if (*((int *)(arg)) >= 0)
			return (write(1, " ", 1));
		else
			return (0);
	}
	else
		return (0);
}
