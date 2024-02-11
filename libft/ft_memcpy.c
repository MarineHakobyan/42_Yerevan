/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:05:09 by marhakob          #+#    #+#             */
/*   Updated: 2022/06/22 00:18:35 by marhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*vpdst;
	char	*vpsrc;

	if (!dst || !src || n)
		return (NULL);
	vpdst = (char *)dst;
	vpsrc = (char *)src;
	while (--n + 1)
		vpdst[n] = vpsrc[n];
	return (dst);
}
