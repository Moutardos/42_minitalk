/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:33:56 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/12/24 01:56:13 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


void handler_letter(int sig, siginfo_t info)
{
    static  unsigned int size = 0;
    static char c = 0;
    if (size == 0)
    {
        size = 1;
    }
    else
    {
        if (sig == SIG_1)
            c += size;
        size *= 2;
    }
    if (size > 128)
    {
        write(1, &c, 1);
        size = 0;
        c = 0;
    }
    kill(info.si_pid, SIG_GOT); 
    
}

int main()
{
    printf("Server started with PID %d\n", getpid());

    // Set up signal handler for incoming signals
    struct sigaction action;
    int i = 1;
    sigemptyset(&action.sa_mask);
    action.sa_flags = SA_RESTART | SA_SIGINFO;
    action.sa_handler = handler_letter;
    sigaction(SIG_1, &action, NULL);
    sigaction(SIG_0, &action, NULL);
    while (1)
    {
        pause(); // Wait for signal
    }

    return 0;
}

