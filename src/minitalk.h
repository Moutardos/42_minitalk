/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:35:12 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/02/06 15:26:48 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <sys/wait.h>
# include <signal.h>
# include "../libft/libft.h"

typedef struct s_msginfo
{
	int		len;
	int		len_done;
	char	*msg;
	int		msg_done;
	int		sig_got;
	pid_t	client_pid;

}	t_msginfo;

typedef enum e_state
{
	INACTIVE,
	SENDING,
	GOT,
	DONE,
}	t_state;

# define WAIT_TIME 200
# define SIG_DONE SIGUSR2
# define SIG_GOT SIGUSR1
# define SIG_1 SIGUSR1
# define SIG_0 SIGUSR2

/** CLIENT **/

/* HANDLER */
/* Handle the 2 different signal : SIG_GOT and SIG_DONE,
   "SIG_GOT" can either mean that the previously inactive processus
   is currrently sending a signal to the server or if it's
   already in the SENDING state the server got the previous signal
   "SIG_DONE" is used when the server got the length of the message
   or fully printed it*/
static void	handler_client(int sig);

/* Halt the curren tprocesssus until the server send a signal to it*/
void		wait_sig(void);

/* send_msg send the message to the target pid by going bit per bit and sending
   either SIG_0 or SIG_1. It also send the NULL character.
   Always wait for the server pid to send a signal to continue.
*/
void		send_msg(pid_t spid, const char *msg);

/* send_len send the length of the message to the target pid by emiting
   SIG_1 until it met the NULL character.
   Always wait for the server pid to send a signal to continue.
   Return 1 if the string is empty and 0 if not.
*/
int			send_len(pid_t spid, const char *msg);

/** SERVER **/
/* HANDLER */
/* Handle the 2 different signal : SIG_0 and SIG_1,
   Depending on when the function is used, it either increase the len size
   or add corresponding value for the bytes of each character.
*/
void		handler_letter(int sig, siginfo_t *info, void *context);
/* Part of the handler that increase the len of the message to malloc it
   afterward. SIG_1 = continue increasing SIG_0 = stop.
*/
void		get_len(int sig);

/* Initalize the global variable to 0 and free the precedent message
*/
void		init_msginfo(void);

/* Treat the current message by waiting for signals and then allocuting
   memory to later print it
*/
int			treat_message(void);
#endif