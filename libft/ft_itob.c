/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:49:29 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/12/03 19:18:35 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_blen(int n, char *base)
{
	int		i;
	size_t	base_size;

	base_size = ft_strlen(base);
	i = 1;
	while (n >= (int) base_size)
	{
		n /= base_size;
		i++;
	}
	return (i);
}

static char	*ft_allocitoa(size_t size, size_t is_minus)
{
	char	*res;

	if (size + 1 + is_minus >= SIZE_MAX)
		return (NULL);
	res = calloc(size + 1 + is_minus, sizeof(char));
	return (res);
}

static	void	ft_negative(size_t *is_minus, int *n)
{
	if (*n < 0)
	{
		*is_minus = 1;
		*n *= -1;
	}
}

/* !! NE TRAITE PAS INT MIN LOOL */
char	*ft_itob(int n, char *base)
{
	size_t	size;
	char	*res;
	size_t	i;
	size_t	is_minus;
	size_t	base_size;

	base_size = ft_strlen(base);
	is_minus = 0;
	i = 0;
	ft_negative(&is_minus, &n);
	size = ft_blen(n, base);
	res = ft_allocitoa(size, is_minus);
	if (res == NULL)
		return (NULL);
	if (is_minus)
		res[0] = '-';
	while ((i) < size)
	{
		res[size - i++ - 1 + is_minus] = base[n % base_size];
		n /= base_size;
	}
	return (res);
}
