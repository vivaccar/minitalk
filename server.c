/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:51:49 by vivaccar          #+#    #+#             */
/*   Updated: 2024/01/31 12:16:23 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ft_printf/ft_printf.h"
#include "signal.h"

void	handler(int bit)
{
	ft_putstr_fd("Exiting the program, SIGUSR1 received!", 1);
	exit(0);
}

int	main(void)
{
	int	pid;

	ft_printf("PROCESS PID: %i\n", getpid());
	signal(SIGUSR1, handler);
	while (1)
	{
		pause();
	}
}
