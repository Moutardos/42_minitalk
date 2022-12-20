/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:35:12 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/12/20 00:44:22 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include "../libft/libft.h"
#include <signal.h>

typedef enum	s_state
{
	WAITING,
	WORKING,
	SENT,
	OVER
} t_state;

typedef struct s_message
{
	unsigned char   *str;
	t_state			status;
	pid_t			cpid;
} t_message;

#define SIGCLIENT SIGUSR1
#define SIGSERVER SIGUSR2


/* Global from server */
extern t_message	*message;

/* Global from client */
extern t_state		is_over;