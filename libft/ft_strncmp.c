/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:25:59 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/11/16 20:02:29 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	if (n == 0 || str1 == NULL || str2 == NULL)
		return (0);
	while (*str1 == *str2 && (*str1 != '\0') && i < n)
	{
		i++;
		if (i != n)
		{
			str1++;
			str2++;
		}
	}
	return (*str1 - *str2);
}
