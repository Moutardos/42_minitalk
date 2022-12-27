/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <loic.cozdenmat@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:43:44 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/11/20 19:41:09 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*mem_s;

	mem_s = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		mem_s[i] = 0;
		i++;
	}
}
