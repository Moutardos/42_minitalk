/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:55:47 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/11/20 18:54:53 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_power(int n)
{
	size_t	pow;

	pow = 1;
	while (n >= 10)
	{
		n /= 10;
		pow++;
	}
	return (pow);
}

static char	*ft_imintoa(void)
{
	return (ft_strdup("-2147483648"));
}

static char	*ft_allocitoa(size_t size, size_t is_minus)
{
	char	*res;

	if (size + 1 + is_minus >= SIZE_MAX)
		return (NULL);
	res = malloc(sizeof(char) * size + 1 + is_minus);
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

char	*ft_itoa(int n)
{
	size_t	size;
	char	*res;
	size_t	i;
	size_t	is_minus;

	if (n == -2147483648)
		return (ft_imintoa());
	is_minus = 0;
	i = 0;
	ft_negative(&is_minus, &n);
	size = ft_get_power(n);
	res = ft_allocitoa(size, is_minus);
	if (res == NULL)
		return (NULL);
	if (is_minus)
		res[0] = '-';
	while ((i) < size)
	{
		res[size - i++ - 1 + is_minus] = n % 10 + '0';
		n /= 10;
	}
	res[size + is_minus] = '\0';
	return (res);
}
