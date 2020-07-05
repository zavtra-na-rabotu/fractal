/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:09:16 by edaella-          #+#    #+#             */
/*   Updated: 2019/03/30 16:09:30 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*retval;
	int		i;
	int		sign;

	sign = n < 0 ? 1 : 0;
	retval = (char*)malloc(sizeof(*retval) * ft_get_digits(n, 10) + sign + 1);
	if (!retval)
		return (NULL);
	i = 0;
	if (n == 0)
		return ("0");
	ft_handle_int_min(&n, &retval, &sign, &i);
	while (n != 0)
	{
		retval[i++] = n % 10 + '0';
		n = n / 10;
	}
	if (sign)
		retval[i++] = '-';
	retval[i] = '\0';
	ft_strrev(retval);
	return (retval);
}

char	*ft_itoa_base(uintmax_t n, int base)
{
	char	*dict;
	char	*retval;
	size_t	i;

	dict = "0123456789abcdef";
	retval = (char *)malloc(sizeof(*retval) * ft_get_digits(n, base) + 1);
	if (!retval)
		return (NULL);
	i = 0;
	if (n == 0)
		return ("0");
	while (n != 0)
	{
		retval[i++] = dict[n % base];
		n = n / base;
	}
	retval[i] = '\0';
	ft_strrev(retval);
	return (retval);
}

char	*ft_uimtoa(uintmax_t n)
{
	return (ft_itoa_base(n, 10));
}
