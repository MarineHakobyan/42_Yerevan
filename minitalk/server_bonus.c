/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 22:19:36 by marihako          #+#    #+#             */
/*   Updated: 2023/09/27 22:23:44 by marihako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	ft_btoa(int sig, siginfo_t *info, void *context)
{
	static unsigned char	received_char = 0;
	static int				bit = 0;

	(void)context;
	(void)info;
	if (sig == SIGUSR1)
		received_char |= (1 << bit);
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
	struct sigaction	act;

	(void)argv;
	if (argc != 1)
	{
		ft_putstr("Error\n");
		return (1);
	}
	print_server_pid();
	act.sa_sigaction = ft_btoa;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	while (42)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		pause();
	}
	return (0);
}
