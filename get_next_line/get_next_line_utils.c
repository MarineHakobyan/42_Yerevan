/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:17:26 by marihako          #+#    #+#             */
/*   Updated: 2023/03/08 22:17:28 by marihako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		++i;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = -1;
	if (!s)
		return (0);
	while (s[++i] != '\0')
		if (s[i] == (char) c)
			return ((char *)&s[i]);
	if (c == '\0')
		return ((char *)&s[++i]);
	return (0);
}

char	*ft_strjoin(char *left_str, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!buffer)
		return (NULL);
	i = ft_strlen(left_str) + ft_strlen(buffer);
	str = malloc(sizeof(char) * i + 1);
	if (str == NULL)
		return (NULL);
	i = -1;
	j = -1;
	if (left_str || ++i)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buffer[++j] != '\0')
		str[i++] = buffer[j];
	str[i] = '\0';
	free(left_str);
	return (str);
}

char	*get_one_line(char *left_str)
{
	int		i;
	char	*str;

	i = 0;
	if (left_str[i] == '\0')
		return (NULL);
	while (left_str[i] != '\0' && left_str[i] != '\n')
		++i;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = -1;
	while (left_str[++i] && left_str[i] != '\n')
		str[i] = left_str[i];
	if (left_str[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*new_ls(char *src)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (src[i] != '\0' && src[i] != '\n')
		++i;
	if (src[i] == '\0')
	{
		free(src);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(src) - i + 1));
	if (!str)
		return (NULL);
	j = -1;
	while (src[++i])
		str[++j] = src[i];
	str[++j] = '\0';
	free(src);
	return (str);
}
