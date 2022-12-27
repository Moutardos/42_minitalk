/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 10:44:46 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/11/20 12:27:06 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free_split(char **res, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

/* count the number of word separated by c in s */
static size_t	ft_wc(char const *s, char c)
{
	size_t	wc;

	wc = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			wc++;
		while (*s && *s != c)
			s++;
	}
	return (wc);
}

/* extract the next word found inside s which is 
   pointed by p_s, p_s then is moved to the end of the word in the string.
   ! p_s must point to the beggining of the word (use ft_next_word)*/
static char	*ft_ext_word(char const **p_s, char c)
{
	size_t	len;
	char	*word;

	len = 0;
	while ((*p_s)[len] && (*p_s)[len] != c)
		len++;
	if (len + 1 > SIZE_MAX)
		return (NULL);
	word = malloc(len + 1);
	if (word == NULL)
		return (NULL);
	ft_strlcpy(word, (*p_s), len + 1);
	*p_s += len;
	return (word);
}

static void	ft_next_word(char const **p_s, char c)
{
	while (**p_s && **p_s == c)
		(*p_s)++;
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	char	*word;
	size_t	i;
	size_t	wc;
	size_t	size;

	wc = ft_wc(s, c);
	i = 0;
	size = 0;
	if (sizeof(char *) * (size + 1) > SIZE_MAX)
		return (NULL);
	res = malloc(sizeof(char *) * (wc + 1));
	if (res == NULL)
		return (NULL);
	while (i < wc)
	{
		ft_next_word(&s, c);
		word = ft_ext_word(&s, c);
		if (word == NULL)
			return (ft_free_split(res, i));
		res[i] = word;
		i++;
	}
	res[i] = NULL;
	return (res);
}
