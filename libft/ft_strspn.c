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

size_t ft_strspn(const char *s, const char *accept)
{
    const char *p;
    
    p = s;
    while (*p && ft_strchr(accept, *p))
        ++p;
    return p - s;
}