/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinivaccari <vinivaccari@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:17:40 by vivaccar          #+#    #+#             */
/*   Updated: 2024/02/08 11:38:20 by vinivaccari      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handlersig(int signal, siginfo_t *info, void *content)
{
	static int				i = 0;
	static int				cur_char = 0;
	int						bit;
	(void) content;

	bit = 0;
	if (signal == SIGUSR2)
		bit = 1;
	cur_char = (cur_char << 1) + bit;
	i++;
	if (i == 8)
	{
		write (1, &cur_char, 1);
		i = 0;
		if (cur_char == '\0')
			kill(info->si_pid, SIGUSR2);
		cur_char = 0;
	}
	usleep(1);
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = &handlersig;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("PROCESS PID: %i\n", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);	
		pause();
	}
}