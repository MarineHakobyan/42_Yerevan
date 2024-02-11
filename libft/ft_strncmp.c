/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 21:40:37 by marhakob          #+#    #+#             */
/*   Updated: 2022/06/22 01:26:11 by marhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = -1;
	while ((s1[++i] || s2[i]) && (i < n))
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char )s2[i]);
	return (0);
}
