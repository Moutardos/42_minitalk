/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:56:22 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/11/25 17:15:25 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, int (*f)(int))
{
	char	*str_res;
	size_t	size;
	size_t	i;

	str_res = ft_strdup(s);
	if (str_res == NULL)
		return (NULL);
	size = ft_strlen(str_res);
	i = 0;
	while (i < size)
	{
		str_res[i] = f(s[i]);
		i++;
	}
	return (str_res);
}
