/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinivaccari <vinivaccari@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:17:53 by vivaccar          #+#    #+#             */
/*   Updated: 2024/02/08 11:05:03 by vinivaccari      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handler(int signal)
{
	if (signal == SIGUSR2)
	{	
		ft_printf("MESSAGE RECEIVED BY THE SERVER!");
		exit (0);
	}
}

void	send_msg(pid_t pid, char *str)
{
	int					i;
	int					j;
	int					bit;
	
	i = 0;
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);	
	while (str[i])
	{
		j = 7;
		while (j >= 0)
		{
			bit = (str[i] >> j) & 1;
			if (bit == 0)
			{
				kill(pid, SIGUSR1);
				pause();
			}
			else
			{	
				kill(pid, SIGUSR2);
				pause();
			}
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
		ft_printf("ERROR: INVALID ARGUMENTS NUMBER!\n");
}