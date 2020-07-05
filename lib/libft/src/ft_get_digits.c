/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_digits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:09:16 by edaella-          #+#    #+#             */
/*   Updated: 2019/03/30 16:09:30 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"

int	ft_get_digits(int n, int base)
{
	int i;

	i = 1;
	while (n /= base)
		i++;
	return (i);
}

int	ft_get_digitsl(long int n, int base)
{
	int i;

	i = 1;
	while (n /= base)
		i++;
	return (i);
}

int	ft_get_digitsll(long long int n, int base)
{
	int i;

	i = 1;
	while (n /= base)
		i++;
	return (i);
}

int	ft_get_digits_uintmax(uintmax_t n, int base)
{
	int i;

	i = 1;
	while (n /= base)
		i++;
	return (i);
}

int	ft_get_digits_intmax(intmax_t n, int base)
{
	int i;

	i = 1;
	while (n /= base)
		i++;
	return (i);
}
