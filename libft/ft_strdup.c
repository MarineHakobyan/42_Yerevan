/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 22:16:33 by marhakob          #+#    #+#             */
/*   Updated: 2022/06/22 00:22:39 by marhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	len;

	len = ft_strlen(s1);
	s2 = malloc(++len);
	if (!s2)
		return (NULL);
	while (--len + 1)
		s2[len] = s1[len];
	return (s2);
}
