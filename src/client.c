/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:34:10 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/02/09 10:36:17 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_start = INACTIVE;

void	handler_client(int sig)
{
	if (sig == SIG_GOT)
	{
		if (g_start == INACTIVE)
			g_start = SENDING;
		else if (g_start == SENDING)
			g_start = GOT;
	}
	else if (sig == SIG_DONE)
	{
		ft_printf("FAIL");
		exit(0);
	}
}

void	wait_sig(void)
{
	while (g_start == SENDING)
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
			g_start = SENDING;
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
		g_start = SENDING;
		kill(spid, SIG_0);
		wait_sig();
	}
}

void	send_len(pid_t spid, const char *msg)
{
	int	len;

	len = 0;
	while (g_start == INACTIVE)
		;
	while (*msg)
	{
		msg++;
		g_start = SENDING;
		kill(spid, SIG_1);
		wait_sig();
		len++;
	}
	kill(spid, SIG_0);
	if (!len)
	{
		printf("DONE");
		exit(0);
	}
}

int	main(int ac, char const **av)
{
	struct sigaction	sa;
	pid_t				spid;

	if ((ac < 2 || ac > 3) || av[2] == NULL)
		return (0);
	spid = ft_atoi(av[1]);
	if (ac == 2)
		kill(spid, SIG_0);
	sa.sa_handler = handler_client;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIG_GOT, &sa, NULL);
	sigaction(SIG_DONE, &sa, NULL);
	kill(spid, SIG_1);
	while (g_start == INACTIVE)
		;
	send_len(spid, av[2]);
	g_start = SENDING;
	while (g_start != GOT)
		;
	send_msg(spid, av[2]);
	printf("DONE");
	return (0);
}
