/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:26:07 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/12/03 19:27:19 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"
#include "stdio.h"

t_atype	ft_get_atype(char c)
{
	if (c == 'c')
		return (A_CHAR);
	if (c == 's')
		return (A_STR);
	if (c == 'p')
		return (A_PT);
	if (c == 'd')
		return (A_DEC);
	if (c == 'i')
		return (A_INT);
	if (c == 'u')
		return (A_UDEC);
	if (c == 'x')
		return (A_HEXLOW);
	if (c == 'X')
		return (A_HEXUP);
	if (c == '%')
		return (A_PERC);
	return (A_NONE);
}

t_ftype	ft_get_ftype(char c)
{
	if (c == ' ')
		return (F_SPACE);
	if (c == '-')
		return (F_MINUS);
	if (c == '0')
		return (F_ZERO);
	if (c == '.')
		return (F_DOT);
	if (c == '#')
		return (F_SHARP);
	if (c == '+')
		return (F_ADD);
	return (F_NONE);
}

int	ft_fill_arg(const char **s, t_arg *arginfo)
{
	int		size;
	t_ftype	ftype;

	size = 0;
	arginfo->ptr = *s;
	ftype = ft_get_ftype(**s);
	size++;
	while (ftype != F_NONE && **s)
	{
		arginfo->flags[ftype] = 1;
		ftype = ft_get_ftype(**s);
		if (ftype == F_NONE)
			break ;
		*s += 1;
		size++;
	}
	if (**s)
	{
		arginfo->ctype = ft_get_atype(**s);
		size++;
		*s += 1;
	}
	return (size);
}
