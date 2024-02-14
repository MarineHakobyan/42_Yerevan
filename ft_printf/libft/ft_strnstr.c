/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:40:57 by marhakob          #+#    #+#             */
/*   Updated: 2022/06/22 01:27:37 by marhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	is_substring_match(const char *haystack, const char *needle,
		size_t i, size_t len)
{
	size_t	j;

	j = 0;
	while (needle[j] && haystack[i + j] == needle[j] && i + j < len)
		++j;
	return (!needle[j]);
}

static int	should_continue_search(const char *haystack, const char *needle,
		size_t i, size_t len)
{
	return (haystack[i] && i < len && !is_substring_match(haystack, needle, i,
			len));
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (!haystack || !needle)
		return (NULL);
	if (!needle[0])
		return ((char *)&haystack[0]);
	i = 0;
	while (should_continue_search(haystack, needle, i, len))
		++i;
	if (is_substring_match(haystack, needle, i, len))
		return ((char *)&haystack[i]);
	return (NULL);
}
