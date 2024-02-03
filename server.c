/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinivaccari <vinivaccari@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:51:49 by vivaccar          #+#    #+#             */
/*   Updated: 2024/02/03 02:06:05 by vinivaccari      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ft_printf/ft_printf.h"
#include "signal.h"

void	handler(int bit)
{
	if (bit == SIGUSR1)
		ft_printf("SIGUSR1 RECEIVED!");
	else
		ft_printf("SIGUSR2 RECEIVED!");
}

int	main(void)
{
	struct sigaction sa;
	
	sa.sa_handler = &handler;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("PROCESS PID: %i\n", getpid());
	while (1)
	{
		pause();
	}
}
