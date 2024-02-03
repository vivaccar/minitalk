/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinivaccari <vinivaccari@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:14:34 by vivaccar          #+#    #+#             */
/*   Updated: 2024/02/03 02:13:40 by vinivaccari      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ft_printf/ft_printf.h"
#include "signal.h"
#include "stdlib.h"

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc == 2)
	{
		pid = (unsigned int)ft_atoi(argv[1]);
		kill(pid, SIGUSR1);
	}
	else
	{
		pid = (unsigned int)ft_atoi(argv[1]);
		kill(pid, SIGUSR1);
	}
}