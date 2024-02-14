/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 23:09:45 by marhakob          #+#    #+#             */
/*   Updated: 2022/06/22 01:23:29 by marhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *print, ...);
int		ft_printf_bonus(const char type, void *arg);
int		ft_type(va_list args, const char type, const char *print);
int		ft_put_hex(unsigned long long n, int type);
int		ft_putitoa_base(unsigned int nbr, char *base);
int		ft_putitoa_base_ptr(unsigned int nbr, char *base);
void	ft_putptr(uintptr_t ptr);
int		ft_ptr(unsigned long long p);
int		ft_ptrlen(uintptr_t ptr);
int		base_choose(unsigned int nbr, char c);

#endif