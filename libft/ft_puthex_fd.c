/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:34:44 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/12/03 19:24:08 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex_fd(size_t n, int fd, unsigned int nsize, int up)
{
	const char			*base = "0123456789abcdef";
	const char			*base_u = "0123456789ABCDEF";
	const size_t		size = 16;
	size_t				mask;
	int					wc;

	mask = 0;
	wc = 0;
	if (nsize > sizeof(size_t))
		return (0);
	mask = ft_pow(2, nsize * 8) - 1;
	n &= mask;
	if (n > size - 1)
	{
		wc = ft_puthex_fd(n / size, fd, nsize, up);
		return (wc + ft_puthex_fd(n % size, fd, nsize, up));
	}
	else
	{
		if (up)
			return (ft_putchar_fd(base_u[n % size], fd));
		return (ft_putchar_fd(base[n % size], fd));
	}
}
