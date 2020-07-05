/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:09:16 by edaella-          #+#    #+#             */
/*   Updated: 2019/03/30 16:09:30 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		normhelper1(size_t *current, char *numasa)
{
	if (numasa[*current] >= '5')
	{
		numasa[*current] = '\0';
		*current -= 1;
		numasa[*current]++;
	}
	else
	{
		numasa[*current] = '\0';
		return (1);
	}
	return (0);
}

int		roundfora(char *numasa)
{
	size_t	current;
	char	sign;

	current = ft_strlen(numasa) - 1;
	sign = *numasa;
	if (normhelper1(&current, numasa))
		return (0);
	while (current && numasa[current] > '9')
	{
		numasa[current] = '0';
		if (numasa[--current] == '.')
			return (1);
		numasa[current]++;
	}
	if (*numasa > '9')
	{
		*numasa = '0';
		ft_strpushfront(numasa, '1');
	}
	if (!ft_isdigit(sign) && sign != '.')
		ft_strpushfront(numasa, sign);
	return (0);
}

void	normhelper2(char *decs, char *wholes)
{
	if (roundfora(decs))
	{
		wholes[ft_strlen(wholes) - 1] += 1;
		roundfora(wholes);
	}
}

char	*ft_dtoa(double num, int precision, int force_dot)
{
	double	dec;
	char	*wholes;
	char	*decs;
	size_t	i;

	decs = malloc(precision + force_dot + 1);
	wholes = num >= 0 ? ft_itoa_base((uintmax_t)num, 10)
					: ft_strjoin("-", ft_itoa_base((uintmax_t)-num, 10));
	dec = num < 0 ? -num - (uintmax_t)-num : num - (uintmax_t)num;
	i = 0;
	if (force_dot || precision)
		decs[i++] = '.';
	while (precision + 1)
	{
		dec *= 10;
		decs[i++] = (char)(((int)dec % 10) + '0');
		precision--;
		dec -= (int)dec;
	}
	decs[i] = '\0';
	normhelper2(decs, wholes);
	return (ft_strjoin(wholes, decs));
}

char	*ft_ldtoa(long double num, int precision, int force_dot)
{
	long double	dec;
	char		*wholes;
	char		*decs;
	size_t		i;

	decs = malloc(precision + force_dot + 1);
	wholes = num >= 0 ? ft_itoa_base((uintmax_t)num, 10)
					: ft_strjoin("-", ft_itoa_base((uintmax_t)-num, 10));
	dec = num < 0 ? -num + (uintmax_t)num : num - (uintmax_t)num;
	i = 0;
	if (force_dot || precision)
		decs[i++] = '.';
	while (precision + 1)
	{
		dec *= 10;
		decs[i++] = (char)(((int)dec % 10) + '0');
		precision--;
		dec -= (int)dec;
	}
	decs[i] = '\0';
	normhelper2(decs, wholes);
	return (ft_strjoin(wholes, decs));
}
