/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:17:53 by vivaccar          #+#    #+#             */
/*   Updated: 2024/03/21 10:13:40 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_received;

void	handler(int signal)
{
	if (signal == SIGUSR1)
		g_received = 1;
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
	int					error;

	error = 0;
	j = 7;
	while (j >= 0)
	{
		g_received = 0;
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		bit = (c >> j) & 1;
		if (bit == 0)
			error = kill(pid, SIGUSR1);
		else
			error = kill(pid, SIGUSR2);
		if (error == -1)
			exit(0);
		while (!g_received)
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
