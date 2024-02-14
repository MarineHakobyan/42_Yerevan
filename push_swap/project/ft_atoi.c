/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:46:51 by marihako          #+#    #+#             */
/*   Updated: 2023/09/17 20:46:57 by marihako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	validate_integer(int minus, long int n)
{
	if (minus == 1 && n > INT_MAX)
		exit_with_error("Error\n");
	else if (minus == -1 && n * minus < INT_MIN)
		exit_with_error("Error\n");
}

int	ft_atoi(const char *str)
{
	int			i;
	int			minus;
	long int	n;

	i = 0;
	minus = 1;
	n = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		++i;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			minus = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - '0');
		++i;
		validate_integer(minus, n);
	}
	return (n * minus);
}
