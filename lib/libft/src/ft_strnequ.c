/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:09:21 by edaella-          #+#    #+#             */
/*   Updated: 2019/03/30 16:09:32 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(const char *s, const char *f, size_t n)
{
	char *str;
	char *to_find;

	str = (char *)s;
	to_find = (char *)f;
	while (*str && *to_find && n)
	{
		if (*str != *to_find)
			return (0);
		str++;
		to_find++;
		n--;
	}
	return (!*to_find || !n);
}
