/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:53:02 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/02/10 17:18:41 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	exit_server(t_msginfo msginfo)
{
	if (msginfo.msg)
		free(msginfo.msg);
	if (msginfo.cpid)
		kill(msginfo.cpid, SIG_DONE);
	exit(0);
}

pid_t	setup_client(int ac, char const **av, void (*handler)(int))
{
	pid_t				spid;
	struct sigaction	sa;

	if ((ac < 2 || ac > 3) || handler == NULL)
		return (0);
	else if (ac == 3 && av[2] == NULL)
		return (0);
	spid = ft_atoi(av[1]);
	if (spid <= 0)
		ft_printf("Nice try !\n");
	if (ac == 2)
	{
		kill(spid, SIG_0);
		usleep(100);
		return (0);
	}
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIG_GOT, &sa, NULL);
	sigaction(SIG_DONE, &sa, NULL);
	kill(spid, SIG_1);
	usleep(100);
	return (spid);
}
