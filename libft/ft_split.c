/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:45:49 by marhakob          #+#    #+#             */
/*   Updated: 2022/06/21 23:18:41 by marhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	**ft_split(char const *s, char c)
{
	int		i;
	int		counter;
	char	**str;
	int		len;

	i = -1;
	counter = 0;
	while (s[++i])
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			++counter;
	str = malloc (sizeof(char *) * (counter + 1));
	if (!s || !str)
		return (NULL);
	str[counter] = 0;
	while (--i >= 0)
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			len = 0;
			while (s[i + len] && s[i + len] != c)
				++len;
			str[--counter] = ft_substr(s, i, len);
		}
	}
	return (str);
}
