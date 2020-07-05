/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:09:16 by edaella-          #+#    #+#             */
/*   Updated: 2019/03/30 16:09:30 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	cpy_from_back(char *d, const char *s, size_t n)
{
	size_t i;

	i = n - 1;
	while (i + 1)
	{
		d[i] = s[i];
		i--;
	}
}

static void	cpy_from_beg(char *d, const char *s, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
}

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = (char *)dest;
	s = (const char *)src;
	if (src < dest)
	{
		cpy_from_back(d, s, n);
	}
	else if (src > dest)
	{
		cpy_from_beg(d, s, n);
	}
	return (dest);
}
