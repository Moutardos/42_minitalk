/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <loic.cozdenmat@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 20:40:30 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/11/10 15:55:34 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*mem_dst;
	unsigned char	*mem_src;
	size_t			i;

	if ((dst == NULL) && (src == NULL))
		return (NULL);
	mem_src = (unsigned char *) src;
	mem_dst = (unsigned char *) dst;
	i = 0;
	while (i < n)
	{
		mem_dst[i] = mem_src[i];
		i++;
	}
	return (dst);
}
