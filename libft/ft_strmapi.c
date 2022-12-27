/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:44:09 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/11/16 19:51:41 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		str_res[i] = f(i, s[i]);
		i++;
	}
	return (str_res);
}
