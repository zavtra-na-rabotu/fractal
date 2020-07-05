/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:09:16 by edaella-          #+#    #+#             */
/*   Updated: 2019/03/30 16:09:30 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwchar(wint_t c)
{
	if (c < 0x007F)
		ft_putchar((char)c);
	else if (c < 0x07FF)
	{
		ft_putchar((char)((c >> 6) + 0b11000000));
		ft_putchar((char)((c & 0b111111) + 0b10000000));
	}
	else if (c < 0xFFFF)
	{
		ft_putchar((char)((c >> 12) + 0b11100000));
		ft_putchar((char)(((c >> 6) & 0b111111) + 0b10000000));
		ft_putchar((char)((c & 0b111111) + 0b10000000));
	}
	else if (c < 0x10FFFF)
	{
		ft_putchar((char)((c >> 18) + 0b11110000));
		ft_putchar((char)(((c >> 12) & 0b111111) + 0b10000000));
		ft_putchar((char)(((c >> 6) & 0b111111) + 0b10000000));
		ft_putchar((char)((c & 0b111111) + 0b10000000));
	}
}
