/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinivaccari <vinivaccari@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:51:49 by vivaccar          #+#    #+#             */
/*   Updated: 2024/03/07 13:03:54 by vinivaccari      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_message	*message;

t_message	*new_node(char c)
{
	t_message	*new;
	
	new = malloc(sizeof(t_message));
	if (!new)
		return (NULL);
	new->c = c;
	new->next = NULL;
	return (new);
}

void	append_node(t_message *new)
{
	t_message			*temp;
	static t_message	*last_node = NULL;

	temp = message;
	if (!message)
	{
		message = new;
		last_node = new;
	}
	else
	{
		last_node->next = new;
		last_node = new;
	}
}

void	print_and_free()
{
	t_message	*temp;
	t_message	*to_free;

	temp = message;
	
	if (!message)
		return ;
	while (temp)
	{
		ft_printf("%c", temp->c);
		temp = temp->next;
	}
	to_free = message;
	while (to_free)
	{
		temp = to_free->next;
		free(to_free);
		to_free = temp;
	}
	message = NULL;
}

void	handlersig(int signal, siginfo_t *info, void *content)
{
	static int				i = 0;
	static int				cur_char = 0;
	int						bit;
	(void) content;
	t_message				*new;

	bit = 0;
	if (signal == SIGUSR2)
		bit = 1;
	cur_char = (cur_char << 1) + bit;
	i++;
	if (i == 8)
	{
		new = new_node(cur_char);
		append_node(new);
		if (cur_char == 0)
			print_and_free();
		i = 0;
		cur_char = 0;
	}
	usleep(1);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	message = NULL;
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
