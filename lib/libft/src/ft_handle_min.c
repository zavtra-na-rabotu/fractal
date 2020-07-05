/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:09:16 by edaella-          #+#    #+#             */
/*   Updated: 2019/03/30 16:09:30 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_handle_int_min(int *n, char **retval, int *sign, int *i)
{
	if (*sign)
	{
		if (*n == -(*n))
		{
			*(retval[*i]) = *n % 10 + '0';
			*n = *n / 10;
			*i += 1;
		}
		*n = -(*n);
	}
}

void	ft_handle_l_min(long int *n, char **retval, int *sign, int *i)
{
	if (*sign)
	{
		if (*n == -(*n))
		{
			*(retval[*i]) = *n % 10 + '0';
			*n = *n / 10;
			*i += 1;
		}
		*n = -(*n);
	}
}
