/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinivaccari <vinivaccari@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:17:53 by vivaccar          #+#    #+#             */
/*   Updated: 2024/02/08 11:31:33 by vinivaccari      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handler(int signal)
{
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
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);	
		bit = (c >> j) & 1;
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