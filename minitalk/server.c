/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:37:23 by marihako          #+#    #+#             */
/*   Updated: 2023/09/27 22:19:27 by marihako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_btoa(int sig)
{
	static int	bit;
	static char	received_char = 0;

	if (sig == SIGUSR1)
		received_char |= (0x01 << bit);
	++bit;
	if (bit == 8)
	{
		ft_putchar(received_char);
		bit = 0;
		received_char = 0;
	}
}

static void	print_server_pid(void)
{
	ft_putstr("server pid: ");
	ft_putnbr(getpid());
	ft_putchar('\n');
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		printf("Error\n");
		return (1);
	}
	print_server_pid();
	while (42)
	{
		signal(SIGUSR1, ft_btoa);
		signal(SIGUSR2, ft_btoa);
		pause();
	}
	return (0);
}
