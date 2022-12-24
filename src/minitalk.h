/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:35:12 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/12/24 01:44:18 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINITALK_H
# define MINITALK_H
# include <sys/wait.h>
# include "../libft/libft.h"
# include <signal.h>

typedef enum e_state
{
    GOT,
    NO_SIG,
    WORKING
} t_state;

# define WAIT_TIME 200
# define SIG_GOT SIGUSR1
# define SIG_1 SIGUSR1
# define SIG_0 SIGUSR2

int     send_signals(pid_t spid,const char *msg);
void    get_signal(void);
int     setup_signals(struct sigaction *sa, struct sigaction *sa_quit);

#endif