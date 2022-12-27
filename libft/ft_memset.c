/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <loic.cozdenmat@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:33:21 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/09/20 21:23:34 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*mem_b;
	unsigned char	mem_c;
	size_t			i;

	mem_b = (unsigned char *)b;
	mem_c = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		mem_b[i] = mem_c;
		i++;
	}
	return (b);
}
