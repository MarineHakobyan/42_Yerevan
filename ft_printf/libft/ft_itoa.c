/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:56:58 by marhakob          #+#    #+#             */
/*   Updated: 2022/04/09 02:12:56 by marhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_len(int n)
{
	int	len;

	len = 1;
	while (n / 10)
	{
		n /= 10;
		++len;
	}
	return (len);
}

char	*ft_fill(char *str, long n, int len, int zerocount)
{
	while (--len)
		zerocount *= 10;
	if (n < 0)
	{
		n *= -1;
		str[len++] = '-';
	}
	while (zerocount)
	{
		str[len++] = n / zerocount + 48;
		n %= zerocount;
		zerocount /= 10;
	}
	str[len] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_len(n);
	if (n < 0)
		str = malloc(len + 2);
	else
		str = malloc(len + 1);
	if (!str)
		return (NULL);
	return (ft_fill(str, n, len, 1));
}
