/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 03:29:42 by ajafy             #+#    #+#             */
/*   Updated: 2021/12/05 11:18:44 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printhexa(unsigned int x, char *tab)
{
	char	c;
	int		res;

	res = 0;
	if (x > 15)
	{
		res += ft_printhexa((x / 16), tab);
		res += ft_printhexa((x % 16), tab);
	}
	if (x < 16)
	{
		c = tab[x];
		res += write(1, &c, 1);
	}
	return (res);
}

int	ft_putentier(int x)
{
	int		res;
	size_t	nbr;

	res = 0;
	nbr = x;
	res += ft_putnbr(nbr);
	return (res);
}

int	ft_printhexa_pointer(unsigned long x, char *tab)
{
	char	c;
	int		res;

	res = 0;
	if (x > 15)
	{
		res += ft_printhexa_pointer((x / 16), tab);
		res += ft_printhexa_pointer((x % 16), tab);
	}
	if (x < 16)
	{
		c = tab[x];
		res += write(1, &c, 1);
	}
	return (res);
}

int	ft_puthexa(void *x, char a)
{
	int				res;
	char			*ltab;
	char			*utab;
	unsigned long	ul;
	unsigned int	ui;

	ul = (unsigned long)x;
	ui = (unsigned int)x;
	res = 0;
	utab = "0123456789ABCDEF";
	ltab = "0123456789abcdef";
	if (a == 'x')
		res += ft_printhexa(ui, ltab);
	else if (a == 'X')
		res += ft_printhexa(ui, utab);
	else
		res += ft_printhexa_pointer(ul, ltab);
	return (res);
}
