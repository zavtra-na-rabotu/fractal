/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:09:20 by edaella-          #+#    #+#             */
/*   Updated: 2019/03/30 16:09:32 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*retval;
	size_t	i;

	i = 0;
	retval = (char *)malloc(ft_strlen(s) + 1);
	if (retval)
	{
		while (s[i])
		{
			retval[i] = f(s[i]);
			i++;
		}
		retval[i] = '\0';
	}
	return (retval);
}
