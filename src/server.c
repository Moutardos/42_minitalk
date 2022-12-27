/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:33:56 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/12/27 21:36:23 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h> 

t_msginfo   *msginfo = NULL;

void handler_letter(int sig, siginfo_t * info, void * context)
{
    static unsigned int pos = 0;
    static unsigned int bit = 0;
	static unsigned int size = 1;
    if (!msginfo->client_pid)
    {
        msginfo->client_pid = info->si_pid;
        return ;
    }
    if (!msginfo->len_done)
    {
		get_len(sig);
    }
    else
    {
        if (sig == SIG_1)
            bit += size;
        size *= 2;
    }
    if (size > 128)
    {
        msginfo->msg[pos] = bit;
        pos++;
		if (bit == 0)
        {
            pos = 0;
			msginfo->msg_done = 1;
        }
        size = 1;
        bit = 0;
    }
}

void get_len(int sig)
{
    if (sig == SIG_1)
        msginfo->len++;
    else if (sig == SIG_0)
		msginfo->len_done = 1;
}

t_msginfo   *init_msginfo(t_msginfo *msginfo)
{
    t_msginfo *newinfo;

    if (!msginfo)
        newinfo = malloc(sizeof(t_msginfo));
    else
        newinfo = msginfo;
    if (!newinfo)
        return (NULL);
    newinfo->len_done = 0;
    newinfo->len = 0;
    if (newinfo->msg)
        free(newinfo->msg);
    newinfo->msg = NULL;
    newinfo->msg_done = 0;
    newinfo->client_pid = 0;
    return (newinfo);
}

int treat_message(void)
{
    if (!msginfo)
        return (0);
    kill(msginfo->client_pid, SIG_GOT);
    while (!msginfo->len_done)
	{
        pause();
        kill(msginfo->client_pid, SIG_GOT);
	}
	if (msginfo->len == 0)
		return (-1);
	msginfo->msg = malloc(msginfo->len + 1);
	if (msginfo->msg == NULL)
		return (0);
    kill(msginfo->client_pid, SIG_DONE);
	while(!msginfo->msg_done)
    {
        pause();
        kill(msginfo->client_pid, SIG_GOT);
    }
    kill(msginfo->client_pid, SIG_GOT);
    kill(msginfo->client_pid, SIG_DONE);
    ft_printf(msginfo->msg);
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
    msginfo = init_msginfo(msginfo);
    if (!msginfo)
        return (0);
    ft_printf("Server started with PID %d\n", getpid());
    while (!msg_err)
    {
		pause();
		msg_err = treat_message();
        if (init_msginfo(msginfo) == NULL)
            break;
    }
	if (msginfo)
	{
		if (msginfo->msg)
			free(msginfo->msg);
		free(msginfo);
	}
    return 0;
}

