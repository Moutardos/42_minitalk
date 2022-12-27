/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:41:43 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/11/25 17:26:53 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlow(char *s)
{
	char	*res;

	if (s == NULL)
		return (NULL);
	res = ft_strmap(s, ft_tolower);
	return (res);
}
