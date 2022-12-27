/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:34:44 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/11/28 20:24:22 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n == -2147483648)
		{
			ft_putchar_fd('2', fd);
			ft_putnbr_fd(147483648, fd);
			return (11);
		}
		else
			return (ft_putnbr_fd(n * -1, fd) + 1);
	}
	else
	{
		if (n > 9)
			return (ft_putnbr_fd(n / 10, fd) + ft_putnbr_fd(n % 10, fd));
		else
			return (ft_putchar_fd('0' + n, fd));
	}
}
