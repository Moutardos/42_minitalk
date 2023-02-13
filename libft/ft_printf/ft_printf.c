/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:12:51 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/02/13 10:43:46 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"

int	ft_print_group(const char **s, t_arg *arginfo)
{
	char	*percent;
	int		char_printed;

	percent = ft_strchr(*s, '%');
	if (percent == NULL)
	{
		ft_putstr_fd((char *) *s, STDOUT);
		char_printed = ft_strlen(*s);
		*s = NULL;
	}
	else
	{
		write(STDOUT, *s, percent - *s);
		char_printed = percent - *s;
		*s += char_printed + 1;
		ft_fill_arg(s, arginfo);
		char_printed += ft_print_arg(arginfo);
	}
	return (char_printed);
}

int	ft_print_arg(t_arg *arginfo)
{
	int		wc;
	int		res;

	wc = 0;
	if (arginfo->ctype == A_DEC || arginfo->ctype == A_INT)
		wc = ft_putnbr_fd(va_arg(*(arginfo->ap), int), STDOUT);
	else if (arginfo->ctype == A_CHAR)
	{
		res = va_arg((*arginfo->ap), int);
		wc = ft_putchar_fd(res, STDOUT);
	}
	else if (arginfo->ctype == A_HEXLOW)
	{
		res = va_arg(*(arginfo->ap), int);
		wc = ft_puthex_fd(res, STDOUT, sizeof(int), 0);
	}
	else if (arginfo->ctype == A_HEXUP)
	{
		res = va_arg(*(arginfo->ap), int);
		wc = ft_puthex_fd(res, STDOUT, sizeof(int), 1);
	}
	else
		return (ft_print_arg2(arginfo));
	return (wc);
}

int	ft_print_arg2(t_arg *arginfo)
{
	int		wc;
	void	*res;

	wc = 0;
	if (arginfo->ctype == A_PERC)
		wc = ft_putchar_fd('%', STDOUT);
	else if (arginfo->ctype == A_UDEC)
		wc = ft_putnbru_fd(va_arg(*(arginfo->ap), unsigned int), STDOUT);
	else if (arginfo->ctype == A_PT)
	{
		res = va_arg(*(arginfo->ap), void *);
		if (res == NULL)
			return (ft_putstr_fd("(nil)", STDOUT));
		wc += ft_putstr_fd("0x", STDOUT);
		wc += ft_puthex_fd((size_t) res, STDOUT, sizeof(size_t), 0);
	}
	else if (arginfo->ctype == A_STR)
	{
		res = va_arg(*(arginfo->ap), char *);
		if (res == NULL)
			wc = ft_putstr_fd("(null)", STDOUT);
		else
			wc = ft_putstr_fd(res, STDOUT);
	}
	return (wc);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	t_arg	*arginfo;
	int		char_printed;

	arginfo = malloc(sizeof(t_arg));
	if (!arginfo)
		return (0);
	char_printed = 0;
	va_start(ap, s);
	arginfo->ap = &ap;
	char_printed += ft_print_group(&s, arginfo);
	while (s != NULL)
	{
		free(arginfo);
		arginfo = malloc(sizeof(t_arg));
		if (!arginfo)
			break ;
		arginfo->ap = &ap;
		char_printed += ft_print_group(&s, arginfo);
	}
	if (arginfo)
		free(arginfo);
	va_end(ap);
	return (char_printed);
}
