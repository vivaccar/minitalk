/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinivaccari <vinivaccari@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:51:49 by vivaccar          #+#    #+#             */
/*   Updated: 2024/02/04 12:20:19 by vinivaccari      ###   ########.fr       */
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
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	ft_printf("PROCESS PID: %i\n", getpid());
	while (1)
		pause();
}
