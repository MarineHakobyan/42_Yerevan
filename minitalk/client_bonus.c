/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 22:15:39 by marihako          #+#    #+#             */
/*   Updated: 2023/09/27 22:15:55 by marihako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	confirm_msg(int signal)
{
	if (signal == SIGUSR2)
		ft_putstr("message recieved\n");
}

void	usage(void)
{
	ft_putstr("usage: ./client [server-pid] [message]\n");
	exit(0);
}

void	ft_atob(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		++bit;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
		usage();
	pid = ft_atoi(argv[1]);
	while (argv[2][i] != '\0')
		ft_atob(pid, argv[2][i++]);
	ft_atob(pid, '\n');
	signal(SIGUSR2, confirm_msg);
	return (0);
}
