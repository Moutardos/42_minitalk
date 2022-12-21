/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:33:56 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/12/21 19:10:52 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// -1 : waiting for input
//  0 : getting client pid
//  1 : working
//

volatile sig_atomic_t is_working = -1;

void handler_letter(int sig)
{
	if (is_working == -1)
		is_working = 0;
	else
	{

	}
}

void
int main()
{
    printf("Server started with PID %d\n", getpid());

    // Set up signal handler for incoming signals
    struct sigaction action;
    sigemptyset(&action.sa_mask);
    action.sa_handler = handle_signal;
    sigaction(SIGUSR1, &action, NULL);

    while (1)
    {
        pause(); // Wait for signal
    }

    return 0;
}

