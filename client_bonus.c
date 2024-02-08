/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinivaccari <vinivaccari@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:17:53 by vivaccar          #+#    #+#             */
/*   Updated: 2024/02/08 12:00:51 by vinivaccari      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	received;

void	handler(int signal)
{
	if (signal == SIGUSR1)
		received = 1;
	if (signal == SIGUSR2)
	{	
		ft_printf("MESSAGE RECEIVED BY THE SERVER!\n");
		exit (0);
	}
}

void	send_msg(pid_t pid, char c)
{
	int					j;
	int					bit;

	j = 7;
	while (j >= 0)
	{
		received = 0;
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);	
		bit = (c >> j) & 1;
		if (bit == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!received)
			pause();
		j--;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	i = 0;
	if (argc == 3)
	{
		pid = (pid_t)ft_atoi(argv[1]);
		while (argv[2][i])
		{
			send_msg(pid, argv[2][i]);
			i++;
		}
		send_msg(pid, '\0');
	}
	else
		ft_printf("ERROR: INVALID ARGUMENTS NUMBER!\n");
}