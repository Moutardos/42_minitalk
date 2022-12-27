/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <loic.cozdenmat@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:01:30 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/11/25 16:02:05 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* set start and end to the index of the trimmed part, return the size of it */
static size_t	wc(char const *s1, char const *set, size_t *start, size_t *end)
{
	size_t	i;

	i = 0;
	while (s1[i] && ft_cinstr(set, s1[i]))
		i++;
	*start = i;
	if (!s1[i])
	{
		*end = i;
		return (*end - *start);
	}
	while (s1[i] && s1[i + 1])
		i++;
	while (i && ft_cinstr(set, s1[i]))
		i--;
	*end = i;
	return (*end - *start + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	size;
	size_t	start;
	size_t	end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	size = wc(s1, set, &start, &end);
	if (size + 1 > SIZE_MAX)
		return (NULL);
	res = malloc(size + 1);
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, (s1 + start), size + 1);
	return (res);
}
