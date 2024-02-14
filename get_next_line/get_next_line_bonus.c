/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:17:54 by marihako          #+#    #+#             */
/*   Updated: 2023/03/08 22:17:56 by marihako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_one_line(int fd, char *str)
{
	char	*buffer;
	int		read_count;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_count = 1;
	while (read_count != 0 && !ft_strchr(str, '\n'))
	{
		read_count = read(fd, buffer, BUFFER_SIZE);
		if (read_count == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_count] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*new_str[69565];

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	new_str[fd] = read_one_line(fd, new_str[fd]);
	if (!new_str[fd])
		return (NULL);
	line = get_one_line(new_str[fd]);
	new_str[fd] = new_ls(new_str[fd]);
	return (line);
}
