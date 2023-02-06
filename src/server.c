/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:33:56 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/02/06 15:28:07 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h> 

volatile t_msginfo	msginfo;

void handler_letter(int sig, siginfo_t * info, void * context)
{
	static unsigned	int pos = 0;
	static unsigned	int bit = 0;
	static unsigned	int size = 1;
	if (!msginfo.client_pid)
	{
		msginfo.client_pid = info->si_pid;
		msginfo.sig_got = 1;
		return ;
	}
	if (!msginfo.len_done)
	{
		get_len(sig);
	}
	else if (!msginfo.msg_done)
	{
		if (sig == SIG_1)
			bit += size;
		size *= 2; 
		if (size > 128)
		{
			msginfo.msg[pos] = bit;
			pos++;
			if (bit == 0)
			{
				pos = 0;
				msginfo.msg_done = 1;
			}
			size = 1;
			bit = 0;
		}
	}
	msginfo.sig_got = 1;
}

void get_len(int sig)
{
	if (sig == SIG_1)
		msginfo.len++;
	else if (sig == SIG_0)
		msginfo.len_done = 1;
}

void    init_msginfo()
{
	msginfo.len_done = 0;
	msginfo.len = 0;
	if (msginfo.msg)
		free(msginfo.msg);
	msginfo.msg = NULL;
	msginfo.msg_done = 0;
	msginfo.sig_got = 0;
}

int treat_message(void)
{
	kill(msginfo.client_pid, SIG_GOT);
	while (!msginfo.len_done)
	{
		while(!msginfo.sig_got)
			;
		msginfo.sig_got = 0;
		if (!msginfo.len_done)
			kill(msginfo.client_pid, SIG_GOT);
	}
	if (msginfo.len == 0)
		return (1);
	msginfo.msg = malloc(msginfo.len + 1);
	if (msginfo.msg == NULL)
		return (0);
	kill(msginfo.client_pid, SIG_DONE);
	while(!msginfo.msg_done)
	{
		while(!msginfo.sig_got)
			;
		msginfo.sig_got = 0;
		if (!msginfo.msg_done)
			kill(msginfo.client_pid, SIG_GOT);
	}
	ft_printf(msginfo.msg);
	return (0);

}
int main(void)
{

	// Set up signal handler for incoming signals
	struct sigaction	action;
	int					msg_err;

	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO | SA_RESTART;
	action.sa_sigaction = &handler_letter;
	sigaction(SIG_1, &action, NULL);
	sigaction(SIG_0, &action, NULL);
	msg_err = 0;
	ft_printf("Server started with PID %d", getpid());
	while (!msg_err)
	{
		init_msginfo();
		ft_printf("\nWaiting for message...\n");
		if (msginfo.client_pid)
			kill(msginfo.client_pid, SIG_DONE);
		msginfo.client_pid = 0;
		while(!msginfo.sig_got)
			;
		msginfo.sig_got = 0;
		msg_err = treat_message();
	}
	if (msginfo.msg)
		free(msginfo.msg);
	kill(msginfo.client_pid, SIG_DONE);
	return 0;
}

