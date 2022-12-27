/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <loic.cozdenmat@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 21:37:41 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/11/20 19:32:10 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	data;
	unsigned char	*mem_s;

	i = 0;
	data = (unsigned char) c;
	mem_s = (unsigned char *) s;
	while (i < n)
	{
		if (mem_s[i] == data)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
