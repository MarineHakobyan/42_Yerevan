/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 23:07:36 by marhakob          #+#    #+#             */
/*   Updated: 2022/05/04 19:12:41 by marhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		i;

	res = ft_strdup(s);
	if (!s || !f || !res)
		return (NULL);
	i = -1;
	while (res[++i])
		res[i] = f(i, res[i]);
	return (res);
}
