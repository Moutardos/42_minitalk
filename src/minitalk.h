/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:35:12 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/12/28 13:39:04 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINITALK_H
# define MINITALK_H
# include <sys/wait.h>
# include <signal.h>
# include "../libft/libft.h"

typedef struct s_msginfo 
{
    int     len;
    int     len_done;
    char    *msg;
    int     msg_done;
    pid_t   client_pid;

} t_msginfo;

typedef enum e_state
{
    INACTIVE,
    SENDING,
    GOT,
    DONE,
} t_state;

# define WAIT_TIME 200
# define SIG_DONE SIGUSR2
# define SIG_GOT SIGUSR1
# define SIG_1 SIGUSR1
# define SIG_0 SIGUSR2


/** CLIENT **/
/* HANDLER*/
int     send_signals(pid_t spid,const char *msg);
void    get_signal(void);
int     setup_signals(struct sigaction *sa, struct sigaction *sa_quit);

/** SERVER **/
/* HANDLER */
void handler_letter(int sig, siginfo_t * info, void * context);

void get_len(int sig);
t_msginfo   *init_msginfo(t_msginfo *msginfo);
int treat_message(void);

#endif