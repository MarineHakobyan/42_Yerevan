/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 23:28:08 by marhakob          #+#    #+#             */
/*   Updated: 2022/06/22 00:09:59 by marhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	c1;

	p = (unsigned char *)s;
	c1 = (unsigned char)c;
	i = -1;
	while (++i < n)
		if (p[i] == c1)
			return ((void *)&p[i]);
	return (NULL);
}
