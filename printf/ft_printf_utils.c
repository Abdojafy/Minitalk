/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 23:08:59 by ajafy             #+#    #+#             */
/*   Updated: 2021/12/05 07:56:41 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr(int nbr)
{
	char	c;
	long	x;
	int		res;

	res = 0;
	x = nbr;
	if (x < 0)
	{
		c = '-';
		res += write (1, &c, 1);
		x = x * (-1);
	}
	if (x > 9)
	{
		res += ft_putnbr (x / 10);
		res += ft_putnbr (x % 10);
	}
	if (x < 10)
	{
		c = x + '0';
		res += write(1, &c, 1);
	}
	return (res);
}

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	if (s)
		write(1, s, ft_strlen(s));
	else
	{
		write(1, "(null)", 6);
		return (6);
	}
	return (ft_strlen(s));
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
	}
	return (i);
}

int	ft_putdecimal_ns(unsigned int x)
{
	char	c;
	int		res;

	res = 0;
	if (x > 9)
	{
		res += ft_putdecimal_ns (x / 10);
		res += ft_putdecimal_ns (x % 10);
	}
	if (x < 10)
	{
		c = x + '0';
		res += write(1, &c, 1);
	}
	return (res);
}
