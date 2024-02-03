/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:14:34 by vivaccar          #+#    #+#             */
/*   Updated: 2024/02/03 18:29:26 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_msg(pid_t pid, char *str)
{
	int		i;
	int		j;
	int		bit;
	
	i = 0;
	while (str[i])
	{
		j = 7;
		while (j >= 0)
		{
			bit = (str[i] >> j) & 1;
			if (bit == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(200);
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