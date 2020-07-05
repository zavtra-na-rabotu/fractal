/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:09:23 by edaella-          #+#    #+#             */
/*   Updated: 2019/03/30 16:09:32 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	retval;
	char	*end;

	retval = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			retval++;
			end = ft_strchrnul(s, c);
			while (s < end)
				s++;
		}
	}
	return (retval);
}

static int		skip_delimiters(char **s, char c)
{
	while (**s == c)
		*s += 1;
	if (**s)
		return (1);
	return (0);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**retval;
	char	*start;
	char	*end;
	size_t	i;

	if ((retval = (char **)malloc(sizeof(char *) * count_words(s, c) + 1)))
	{
		i = 0;
		start = (char *)s;
		while (*start)
		{
			if (!skip_delimiters(&start, c))
				break ;
			end = ft_strchrnul(start, c);
			if (!(retval[i] = ft_strcut(start, end)))
			{
				free((void *)retval);
				return (NULL);
			}
			start = end;
			i++;
		}
		retval[i] = 0;
	}
	return (retval);
}
