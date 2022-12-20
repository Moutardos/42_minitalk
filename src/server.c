/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:33:56 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/12/20 01:25:47 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_message *message;

static void	handler(int sig)
{
	if (message->status == WAITING)
		message->status = WORKING;
}

static void handler_quit(int sig)
{
	message->status = OVER;
}

void setup_signals(struct sigaction *sa, struct sigaction *sa_quit)
{
	sa->sa_handler = handler;
	sigemptyset(&sa->sa_mask);
	sa->sa_flags = SA_RESTART;
	sigaction(SIGCLIENT, sa, NULL);
	sa_quit->sa_handler = handler_quit;
	sigemptyset(&sa_quit->sa_mask);
	sa_quit->sa_flags = SA_RESTART;
	sigaction(SIGQUIT, sa_quit, NULL);
	sigaction(SIGINT, sa_quit, NULL);
	sigaction(SIGTERM, sa_quit, NULL);
}
void get_signal(void)
{
	while(message->status != OVER)
	{
		pause();
		if (message->status == WORKING)
		{
			ft_printf("%s", message->str);
			kill(message->cpid, SIGCLIENT);
			message->status = WAITING;
		}
	}
}
int main(void)
{
	struct sigaction	sa;
	struct sigaction	sa_quit;

	message = malloc(sizeof(*message));
	if (message == NULL)
		return (NULL);
	message->str = NULL;
	message->status = WAITING;
	ft_printf("%d", getpid());
	setup_signals(&sa, &sa_quit);
	get_signal();
	return (0);
}