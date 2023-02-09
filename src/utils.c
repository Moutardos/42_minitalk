/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:53:02 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/02/09 12:12:18 by lcozdenm         ###   ########.fr       */
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
