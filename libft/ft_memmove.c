/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 21:45:56 by marhakob          #+#    #+#             */
/*   Updated: 2022/06/22 00:19:02 by marhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst1;
	const char	*src1;
	size_t		i;

	if (!dst || !src || len)
		return (NULL);
	dst1 = (char *)dst;
	i = -1;
	src1 = (char *)src;
	if (src < dst)
		while (--len + 1)
			dst1[len] = src1[len];
	else
		while (++i < len)
			dst1[i] = src1[i];
	return (dst);
}
