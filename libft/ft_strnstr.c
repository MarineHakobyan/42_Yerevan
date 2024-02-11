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

static char	*boyer_moore_search(const char *haystack, const char *needle,
				size_t len);
static char	*kmp_search(const char *haystack, const char *needle, size_t len);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	if (!haystack || !needle || len == 0 || ft_strlen(needle) > len)
		return (NULL);
	needle_len = ft_strlen(needle);
	if (needle_len == 1)
		return (ft_memchr(haystack, *needle, len));
	else if (needle_len <= 8 || ft_strspn(needle, " ") == needle_len)
		return (boyer_moore_search(haystack, needle, len));
	else
		return (kmp_search(haystack, needle, len));
}

static char	*boyer_moore_search(const char *haystack, const char *needle,
		size_t len)
{
	size_t	needle_len;
	int		bad_char_shift[256];
	int		i;
	int		j;

	needle_len = ft_strlen(needle);
	for (i = 0; i < 256; ++i)
		bad_char_shift[i] = needle_len;
	for (i = 0; i < (int)needle_len - 1; ++i)
		// Fix: cast needle_len to int for comparison
		bad_char_shift[(int)needle[i]] = needle_len - i - 1;
	i = 0;
	while (i <= (int)len - (int)needle_len)
	{
		j = needle_len - 1;
		while (j >= 0 && needle[j] == haystack[i + j])
			--j;
		if (j < 0)
			return ((char *)haystack + i);
		else
			i += bad_char_shift[(int)haystack[i + needle_len - 1]];
	}
	return (NULL);
}

static char	*kmp_search(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	int		prefix[256];
	int		k;
	int		i;
	int		j;

	needle_len = ft_strlen(needle);
	prefix[0] = -1;
	k = -1;
	for (i = 1; i < 256; ++i)
		prefix[i] = 0;
	for (i = 1; i < (int)needle_len; ++i)
	{
		while (k >= 0 && needle[i] != needle[k + 1])
			k = prefix[k];
		if (needle[i] == needle[k + 1])
			++k;
		prefix[i] = k;
	}
	i = 0;
	j = 0;
	while (i < (int)len && j < (int)needle_len)
	{
		if (needle[j] == haystack[i])
		{
			++i;
			++j;
			if (j == (int)needle_len)
				return ((char *)haystack + i - needle_len);
		}
		else if (j == 0)
			++i;
		else
			j = prefix[j - 1] + 1;
	}
	return (NULL);
}
