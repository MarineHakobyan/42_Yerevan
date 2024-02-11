/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 21:35:07 by marhakob          #+#    #+#             */
/*   Updated: 2022/06/22 00:22:23 by marhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	c1;

	c1 = (unsigned char)c;
	i = -1;
	while (s[++i])
		if (s[i] == c1)
			return ((char *)&s[i]);
	if (c1 == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
