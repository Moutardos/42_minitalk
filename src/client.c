/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:34:10 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/12/20 01:48:22 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_state	is_over = WAITING;

static void handler(int sig)
{
	if (!is_over)
		is_over = OVER;

}

void	send_signals(pid_t spid, char *str, struct sigaction sa)
{

	while(is_over != OVER)
	{
		wait(NULL);
		usleep(1000);
		if (message->status == WAITING && is_over == WAITING)
		{
			message->str = str;
			kill(spid, SIGCLIENT);
		}
	}
}
int main(int ac, char const **av)
{
	struct sigaction	sa;
	pid_t				spid;

	if (message == NULL)
		return (0);
	if (ac != 3)
		return (0);
	spid = av[1];
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGSERVER, &sa, NULL);
	send_signals(spid, av[2], sa);
	return (0);
}