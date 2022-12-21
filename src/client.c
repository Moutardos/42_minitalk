/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:34:10 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/12/21 18:57:00 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t start = 0;

static void handler_start(int sig)
{
	if (!start)
		start = 1;
}

void	send_signals(pid_t spid, char *msg)
{
	unsigned int	i;

	pause();
	while (*msg)
	{
		i = 0;
		while (i < 8)
		{
			if (start)
			if (*msg >> i)
				kill(spid, SIGUSR1);
			else
				kill(spid, SIGUSR2);
			i++;
		}
		msg++;
	}
}
int main(int ac, char const **av)
{
	struct sigaction	sa;
	pid_t				spid;
	
	if (ac != 3 || av[2] == NULL)
		return (0);
	spid = ft_atoi(av[1]);
	sa.sa_handler = handler_start;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	send_signals(spid, av[2]);
	return (0);
}