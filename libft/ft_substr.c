/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 21:31:51 by marhakob          #+#    #+#             */
/*   Updated: 2022/06/14 01:30:05 by marhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = ft_strlen(s);
	if (i > start)
		i -= start;
	else
		i = 0;
	if (i > len)
		i = len;
	if (s)
	{
		sub = (char *)malloc(sizeof(char) * ++i);
		if (sub)
			ft_strlcpy(sub, s + start, i);
		return (sub);
	}
	return (NULL);
}
