/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 21:35:31 by marhakob          #+#    #+#             */
/*   Updated: 2022/03/22 21:44:05 by marhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	c1;

	i = 0;
	c1 = (unsigned char)c;
	i = ft_strlen(s);
	if (c1 == '\0')
		return ((char *)&s[i]);
	while (--i >= 0)
		if (s[i] == c1)
			return ((char *)&s[i]);
	if (s[i] == c1)
		return ((char *)&s[i]);
	return (NULL);
}
