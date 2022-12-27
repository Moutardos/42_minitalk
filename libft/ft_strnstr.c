/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:03:57 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/11/20 17:57:16 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (big == NULL || little == NULL || little[0] == '\0')
		return ((char *) big);
	while (i < len && big[i] != '\0')
	{
		if (big[i] == little[j])
			j++;
		else if (j > 0)
		{
			i -= j;
			j = 0;
		}
		if (little[j] == '\0')
		{
			return ((((char *) big + i - j +1)));
		}
		i++;
	}
	return (NULL);
}
/*
int	main(int ac, char ** av)
{
	printf("%s dans %s --> %s\n",
	av[2], av[1], ft_strnstr(av[1], av[2], ft_atoi(av[3])));
}
*/
