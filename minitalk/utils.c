/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:13:11 by marihako          #+#    #+#             */
/*   Updated: 2023/09/27 22:27:02 by marihako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_iswhitespace(int c)
{
	return ((c == ' ') || (c >= '\t' && c <= '\r'));
}

int	ft_atoi(const char *str)
{
	int	i;
	int	min;
	int	num;

	i = 0;
	min = 1;
	num = 0;
	while (ft_iswhitespace(str[i]))
		++i;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			min *= -1;
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + (str[i++] - '0');
	return (min * num);
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		if (n == -2147483648)
			ft_putstr("2147483648");
		else
			ft_putnbr(-n);
	}
	else if (n < 10)
		ft_putchar(n + '0');
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return ;
	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
}
