/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:17:40 by vivaccar          #+#    #+#             */
/*   Updated: 2024/02/04 21:27:50 by vivaccar         ###   ########.fr       */
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
		if (cur_char == 0)
		{
			usleep(1);
			kill(info->si_pid, SIGUSR2);
		}
		cur_char = 0;
	}
	if (cur_char != 0)
	{
		usleep(1);
		kill(info->si_pid, SIGUSR2);		
	}
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = &handlersig;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("PROCESS PID: %i\n", getpid());
	while (1)
		pause();
}