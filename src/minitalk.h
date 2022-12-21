/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:35:12 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/12/21 18:51:57 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINITALK_H
# define MINITALK_H
# include <sys/wait.h>
# include "../libft/libft.h"
# include <signal.h>


/* Global from server */

/* Global from client */

void	send_signals(pid_t spid, char *msg);
void get_signal(void);
void setup_signals(struct sigaction *sa, struct sigaction *sa_quit);
#endif