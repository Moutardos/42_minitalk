/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:34:10 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/12/24 01:56:09 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
 
volatile sig_atomic_t start = NO_SIG;

static void handler_got(int sig)
{
	if (start == NO_SIG)
		start = GOT;
	write(1,"go", 2);
}

int	send_signals(pid_t spid,const char *msg)
{
	unsigned int	i;
	while (*msg)
	{
		printf("treating %c\n",*msg);
		kill(spid, SIG_0);
		i = 0;
		while (i < 8)
		{
			usleep(200);
			if (start == NO_SIG)
			{
				printf("fail");
				return (0);
			}
			start = NO_SIG;	
			if (*msg >> i & 1)
				kill(spid, SIG_1);
			else
				kill(spid, SIG_0);
			i++;
			usleep(200);
			printf("%u", i);
		}
		msg++;
	}
	if (*msg)
		return (0);
	return (1);
}
int main(int ac, char const **av)
{
	struct sigaction	sa;
	pid_t				spid;
	
	if (ac != 3 || av[2] == NULL)
		return (0);
	spid = ft_atoi(av[1]);
	sa.sa_handler = handler_got;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIG_GOT, &sa, NULL);
	printf("let's go : %s   ", av[2]);
	send_signals(spid, av[2]);
	return (0);
}