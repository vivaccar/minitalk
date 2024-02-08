/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinivaccari <vinivaccari@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:14:34 by vivaccar          #+#    #+#             */
/*   Updated: 2024/02/08 11:54:13 by vinivaccari      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	received;

void	handler(int signal)
{
	if (signal == SIGUSR1)
		received = 1;
}

void	send_msg(pid_t pid, char *str)
{
	int					i;
	int					j;
	int					bit;
	
	i = 0;
	while (str[i])
	{
		j = 7;
		while (j >= 0)
		{
			received = 0;
			signal(SIGUSR1, handler);
			bit = (str[i] >> j) & 1;;
			if (bit == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			while (!received)
				pause();
			j--;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc == 3)
	{
		pid = (pid_t)ft_atoi(argv[1]);
		send_msg(pid, argv[2]);
	}
	else
		ft_printf("ERROR: INVALID ARGUMENTS\n");
}