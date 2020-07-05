/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:09:17 by edaella-          #+#    #+#             */
/*   Updated: 2019/03/30 16:09:31 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t i;
	size_t offset;

	i = 0;
	offset = ft_strlen(dest);
	while (src[i])
	{
		dest[offset + i] = src[i];
		i++;
	}
	dest[offset + i] = '\0';
	return (dest);
}
