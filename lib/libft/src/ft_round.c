/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:09:17 by edaella-          #+#    #+#             */
/*   Updated: 2019/03/30 16:09:30 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uintmax_t	ft_floor(long double num)
{
	return ((uintmax_t)num);
}

uintmax_t	ft_ceil(long double num)
{
	return ((uintmax_t)num + 1);
}

uintmax_t	ft_round(long double num)
{
	return (ft_floor(num + 0.5));
}
