/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:09:24 by edaella-          #+#    #+#             */
/*   Updated: 2019/03/30 16:09:32 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_whitespace(char c)
{
	return ((c == ' ') || (c == '\t') || (c == '\n'));
}

static const char	*set_start(const char *src)
{
	while (ft_whitespace(*src))
		src++;
	return (src);
}

static const char	*set_end(const char *src)
{
	while (*src)
		src++;
	src--;
	while (ft_whitespace(*src))
		src--;
	return (src);
}

char				*ft_strtrim(char const *s)
{
	char	*retval;
	char	*end;
	char	*start;
	size_t	i;

	i = 0;
	start = (char *)set_start(s);
	if (!*start)
		return ("");
	end = (char *)set_end(s);
	retval = (char *)malloc(end - start + 2);
	if (retval)
	{
		while (start <= end)
		{
			retval[i] = *start;
			start++;
			i++;
		}
		retval[i] = '\0';
	}
	return (retval);
}
