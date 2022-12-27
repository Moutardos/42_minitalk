/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:34:10 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/12/27 23:04:46 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
 
volatile sig_atomic_t start = INACTIVE;

static void handler_client(int sig)
{
	if (sig == SIG_GOT)
	{
		if (start == INACTIVE)
			start = SENDING;
		else if (start == SENDING)
			start = GOT;
	}
	else if (sig == SIG_DONE)
	{
		start = DONE;
	}
}



int	send_msg(pid_t spid,const char *msg)
{
	unsigned int	i;

	while (*msg)
	{
		printf("treating %c\n",*msg);
		i = 0;
		while (i < 8)
		{
			start = SENDING;
			if (*msg >> i & 1)
				kill(spid, SIG_1);
			else
				kill(spid, SIG_0);
			i++;
			pause();
			printf("%u", i);
		}
		msg++;
	}
	i = 0;
	while (i < 8)
	{
		start = SENDING;
		kill(spid, SIG_0);
		pause();
		i++;
	}
	return (1);
}

int	send_len(pid_t spid, const char *msg)
{
	while (start == INACTIVE)
		pause();
	while (*msg)
	{
		kill(spid, SIG_1);
		msg++;
		start = SENDING;
		pause();	
	}
	kill(spid, SIG_0);
}
int main(int ac, char const **av)
{
	struct sigaction	sa;
	pid_t				spid;
	
	if (ac != 3 || av[2] == NULL)
		return (0);
	spid = ft_atoi(av[1]);
	sa.sa_handler = handler_client;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIG_GOT, &sa, NULL);
	sigaction(SIG_DONE, &sa, NULL);
	kill(spid, SIG_1);
	send_len(spid, av[2]);
	while (start != DONE)
		pause();
	send_msg(spid, av[2]);
	pause();
	if (start == END)
		printf("DONE");
	else
		printf("FAIL");
	return (0);
}