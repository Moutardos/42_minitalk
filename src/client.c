/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:34:10 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/02/10 14:51:57 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_state = INACTIVE;

void	handler_client(int sig)
{
	if (sig == SIG_GOT)
	{
		if (g_state == INACTIVE)
			g_state = SENDING;
		else if (g_state == SENDING)
			g_state = GOT;
	}
	else if (sig == SIG_DONE)
	{
		ft_printf("FAIL");
		exit(0);
	}
}

void	wait_sig(void)
{
	while (g_state == SENDING)
		;
}

void	send_msg(pid_t spid, const char *msg)
{
	unsigned int	i;

	while (*msg)
	{
		i = 0;
		while (i < 8)
		{
			g_state = SENDING;
			if (*msg >> i & 1)
				kill(spid, SIG_1);
			else
				kill(spid, SIG_0);
			i++;
			wait_sig();
		}
		msg++;
	}
	i = 0;
	while (i++ < 8)
	{
		g_state = SENDING;
		kill(spid, SIG_0);
		wait_sig();
	}
}

void	send_len(pid_t spid, const char *msg)
{
	int	len;

	len = 0;
	while (g_state == INACTIVE)
		;
	while (*msg)
	{
		msg++;
		g_state = SENDING;
		kill(spid, SIG_1);
		wait_sig();
		len++;
	}
	kill(spid, SIG_0);
	if (!len)
	{
		ft_printf("DONE");
		exit(0);
	}
}

int	main(int ac, char const **av)
{
	pid_t				spid;

	spid = setup_client(ac, av, handler_client);
	if (!spid)
		return (0);
	if (g_state == INACTIVE)
		ft_printf("Couldn't connect to server pid: %d\n", av[2]);
	send_len(spid, av[2]);
	g_state = SENDING;
	while (g_state != GOT)
		;
	send_msg(spid, av[2]);
	ft_printf("DONE");
	return (0);
}
