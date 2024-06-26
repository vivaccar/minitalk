/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:14:34 by vivaccar          #+#    #+#             */
/*   Updated: 2024/03/19 10:58:32 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_received;

void	handler(int signal)
{
	if (signal == SIGUSR1)
		g_received = 1;
}

void	ft_kill(int bit, pid_t pid)
{
	int	error;

	if (bit == 0)
		error = kill(pid, SIGUSR1);
	else
		error = kill(pid, SIGUSR2);
	if (error == -1)
		exit(0);
}

void	send_msg(pid_t pid, char *str)
{
	int					i;
	int					j;
	int					bit;

	i = 0;
	while (1)
	{
		j = 7;
		while (j >= 0)
		{
			g_received = 0;
			signal(SIGUSR1, handler);
			bit = (str[i] >> j) & 1;
			ft_kill(bit, pid);
			while (!g_received)
				pause();
			j--;
		}
		i++;
		if (str[i - 1] == '\0')
			break ;
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
