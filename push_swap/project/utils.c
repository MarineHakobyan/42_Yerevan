/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:47:47 by marihako          #+#    #+#             */
/*   Updated: 2023/09/17 21:49:55 by marihako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i] != '\0')
		++i;
	return (i);
}

void	ft_putstr(char *s)
{
	int	i;

	i = ft_strlen(s);
	write (2, &s[0], i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = -1;
	while (s1[++j])
		str[i++] = s1[j];
	j = -1;
	while (s2[++j])
		str[i++] = s2[j];
	str[i] = 0;
	free(s1);
	return (str);
}

void	exit_with_error(char *s)
{
	ft_putstr(s);
	exit (0);
}
