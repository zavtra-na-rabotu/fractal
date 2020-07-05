/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:09:20 by edaella-          #+#    #+#             */
/*   Updated: 2019/03/30 16:09:32 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len;
	size_t	slen;

	len = 0;
	slen = ft_strlen(src);
	while (*dest && size > 0)
	{
		dest++;
		len++;
		size--;
	}
	while (*src && size-- > 1)
		*dest++ = *src++;
	if (size == 1 || !*src)
		*dest = '\0';
	return (slen + len);
}
