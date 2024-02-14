/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 04:19:40 by marhakob          #+#    #+#             */
/*   Updated: 2022/04/10 18:08:11 by marhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*str;
	int			len;
	int			i;

	len = ft_strlen(s1);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		++i;
	len -= 1;
	while (i <= len && ft_strchr(set, s1[len]))
		--len;
	if (i > len)
		str = ft_strdup("");
	else
		str = ft_substr(s1, i, len - i + 1);
	return (str);
}
