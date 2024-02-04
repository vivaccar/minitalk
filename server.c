/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinivaccari <vinivaccari@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:51:49 by vivaccar          #+#    #+#             */
/*   Updated: 2024/02/04 01:16:51 by vinivaccari      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signal)
{
	static int	i = 0;
	static int	cur_char = 0;
	int			bit;

	bit = 0;
	if (signal == SIGUSR2)
		bit = 1;
	cur_char = (cur_char << 1) + bit;
	i++;
	if (i == 8)
	{
		write (1, &cur_char, 1);
		i = 0;
		cur_char = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
