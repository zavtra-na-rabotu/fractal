/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:09:18 by edaella-          #+#    #+#             */
/*   Updated: 2019/03/30 16:09:32 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	src_len;
	size_t	i;
	char	*mem;

	src_len = ft_strlen(src);
	mem = malloc(sizeof(*src) * src_len + 1);
	if (!mem)
		return (NULL);
	i = 0;
	while (i < src_len)
	{
		mem[i] = src[i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
