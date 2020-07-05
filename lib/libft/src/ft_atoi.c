/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:09:16 by edaella-          #+#    #+#             */
/*   Updated: 2019/03/30 16:09:30 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
			|| c == '\v' || c == '\f' || c == '\r');
}

static void		deal_with_spaces_and_sign(int *sign, size_t *i, const char *s)
{
	while (ft_isspace(s[*i]))
		*i += 1;
	*sign = s[*i] == '-' ? -1 : 1;
	if (s[*i] == '+' || s[*i] == '-')
		*i += 1;
}

int				ft_atoi(const char *str)
{
	long	result;
	long	tmp;
	size_t	i;
	int		sign;

	result = 0;
	i = 0;
	deal_with_spaces_and_sign(&sign, &i, str);
	while (ft_isdigit(str[i]))
	{
		tmp = result;
		result = result * 10 + str[i] - '0';
		if (tmp > result)
		{
			if (sign < 0)
				return (0);
			else
				return (-1);
		}
		i++;
	}
	return ((int)result * sign);
}

int				base_to_uint(char *base, char c)
{
	int i;

	i = 0;
	while (base[i] && base[i] != c)
		i++;
	return (base[i] ? i : -1);
}

int				ft_atoi_base(char *str, char *base)
{
	unsigned int	result;
	int				tmp;
	size_t			i;
	int				len;

	result = 0;
	i = 0;
	len = (int)ft_strlen(base);
	while (ft_isspace(str[i]))
		i += 1;
	while (str[i] && ft_strchr(base, ft_tolower(str[i])))
	{
		tmp = base_to_uint(base, (char)ft_tolower(str[i]));
		if (tmp == -1)
			return (-1);
		result = result * len + tmp;
		i++;
	}
	return (result);
}
