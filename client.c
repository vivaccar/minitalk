/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:14:34 by vivaccar          #+#    #+#             */
/*   Updated: 2024/01/31 12:18:45 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ft_printf/ft_printf.h"
#include "signal.h"
#include "stdlib.h"

int	main(int argc, char **argv)
{
	int	pid;
	
	if (argc == 2)
	{
		pid = ft_atoi(argv[1]);
		kill(pid, SIGUSR1);
	}
}