/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrnul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:09:18 by edaella-          #+#    #+#             */
/*   Updated: 2019/03/30 16:09:31 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchrnul(const char *start, char c)
{
	char *found;

	found = ft_strchr(start, c);
	if (found)
		return (found);
	return (ft_strchr(start, '\0'));
}
