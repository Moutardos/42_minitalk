/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:07:21 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/12/03 01:23:48 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_H
# define ARGS_H
# include "stdarg.h"
# define FLAG_NB 6

/* Array of flags, t_flags[flag] return 1 if the flag is set, else 0*/
typedef int		t_flags[6];

/* Type of the argument, A_NONE if the character is not implemented*/
typedef enum e_atype
{
	A_NONE,
	A_CHAR,
	A_STR,
	A_PT,
	A_DEC,
	A_INT,
	A_UDEC,
	A_HEXLOW,
	A_HEXUP,
	A_PERC
}	t_atype;

/* Type of flag*/
typedef enum e_ftype
{
	F_NONE,
	F_MINUS,
	F_ZERO,
	F_DOT,
	F_SHARP,
	F_SPACE,
	F_ADD
}	t_ftype;

/* Regroup all the information known about the argument*/
typedef struct s_arg
{
	t_atype		ctype;
	t_flags		flags;
	va_list		*ap;
	const char	*ptr;
}	t_arg;

/* return the type linked to the character, return A_NONE if none found */
t_atype	ft_toarg(char c);

/* return the flagtype linked to the character, return F_NONE if none found */
t_ftype	ft_get_ftype(char c);

/* treat and print the data inside arginfo*/
int		ft_treat_arg(char **s, t_arg *arginfo);

/* fill the data of arginfo for the current argument */
int		ft_fill_arg(const char **s, t_arg *arginfo);
#endif
