/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:09:17 by edaella-          #+#    #+#             */
/*   Updated: 2019/03/30 16:09:31 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	char *finder;

	finder = (char *)src;
	while (*finder)
	{
		if (*finder == c)
			return (finder);
		finder++;
	}
	if (!c)
		return (finder);
	return (NULL);
}
