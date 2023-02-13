/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:33:56 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/02/13 11:14:55 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h> 

volatile t_msginfo	g_msginfo;

void	handler_letter(int sig, siginfo_t *info, void *c)
{
	static unsigned int	pos = 0;
	static unsigned int	bit = 0;
	static unsigned int	size = 1;

	if (g_msginfo.sig_got || (g_msginfo.cpid && info->si_pid != g_msginfo.cpid))
		exit_server(g_msginfo);
	else if (!g_msginfo.len_done)
		get_len(sig, info, c);
	else if (!g_msginfo.msg_done)
	{
		if (sig == SIG_1)
			bit += size;
		size *= 2;
		if (size > 128)
		{
			g_msginfo.msg[pos++] = bit;
			if (bit == 0)
				pos = 0;
			if (pos == 0)
				g_msginfo.msg_done = 1;
			size = 1;
			bit = 0;
		}
	}
	g_msginfo.sig_got = 1;
}

void	get_len(int sig, siginfo_t *info, void *c)
{
	(void) c;
	if (!g_msginfo.cpid)
	{
		if (sig == SIG_1)
			g_msginfo.cpid = info->si_pid;
		else if (sig == SIG_0)
			exit_server(g_msginfo);
	}
	else
	{
		if (sig == SIG_1)
			g_msginfo.len++;
		else if (sig == SIG_0)
			g_msginfo.len_done = 1;
	}
}

void	treat_message(void)
{
	kill(g_msginfo.cpid, SIG_GOT);
	while (!g_msginfo.len_done)
	{
		while (!g_msginfo.sig_got)
			;
		g_msginfo.sig_got = 0;
		if (!g_msginfo.len_done)
			kill(g_msginfo.cpid, SIG_GOT);
	}
	if (g_msginfo.len == 0)
		return ;
	g_msginfo.msg = malloc(g_msginfo.len + 1);
	if (!g_msginfo.msg)
		exit_server(g_msginfo);
	kill(g_msginfo.cpid, SIG_GOT);
	while (!g_msginfo.msg_done)
	{
		while (!g_msginfo.sig_got)
			;
		g_msginfo.sig_got = 0;
		if (!g_msginfo.msg_done)
			kill(g_msginfo.cpid, SIG_GOT);
	}
	ft_printf(g_msginfo.msg);
}

void	init_g_msginfo(void)
{
	g_msginfo.len_done = 0;
	g_msginfo.len = 0;
	if (g_msginfo.msg)
		free(g_msginfo.msg);
	g_msginfo.msg = NULL;
	g_msginfo.msg_done = 0;
	g_msginfo.sig_got = 0;
	g_msginfo.cpid = 0;
	ft_printf("\nWaiting for message...\n");
}

int	main(void)
{
	struct sigaction	action;
	int					msg_err;

	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO | SA_RESTART;
	action.sa_sigaction = &handler_letter;
	sigaction(SIG_1, &action, NULL);
	sigaction(SIG_0, &action, NULL);
	msg_err = 0;
	ft_printf("Server started with PID %d", getpid());
	while (1)
	{
		init_g_msginfo();
		while (!g_msginfo.sig_got)
			;
		g_msginfo.sig_got = 0;
		treat_message();
		if (g_msginfo.cpid)
			kill(g_msginfo.cpid, SIG_GOT);
	}
	return (0);
}
