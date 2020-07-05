/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:09:18 by edaella-          #+#    #+#             */
/*   Updated: 2019/03/30 16:09:32 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(char *start, char *end)
{
	char	*retval;
	size_t	i;

	retval = (char *)malloc(end - start + 1);
	i = 0;
	if (retval)
	{
		while (start < end)
		{
			retval[i] = *start;
			start++;
			i++;
		}
		retval[i] = '\0';
	}
	return (retval);
}
