/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:24:51 by ajafy             #+#    #+#             */
/*   Updated: 2021/12/05 11:18:07 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libftprintf.h"

int	ft_check_args(va_list lst, const char *s, int i)
{
	int	res;

	res = 0;
	if (s[i] == 'd')
		res += ft_putnbr(va_arg(lst, int));
	else if (s[i] == 'c')
		res += ft_putchar(va_arg(lst, int));
	else if (s[i] == 's')
		res += ft_putstr(va_arg(lst, char *));
	else if (s[i] == 'p')
	{
		res += ft_putstr("0x");
		res += ft_puthexa(va_arg(lst, void *), s[i]);
	}
	else if (s[i] == 'i')
		res += ft_putnbr(va_arg(lst, int));
	else if (s[i] == 'u')
		res += ft_putdecimal_ns(va_arg(lst, unsigned int));
	else if (s[i] == 'x')
		res += ft_puthexa(va_arg(lst, void *), s[i]);
	else if (s[i] == 'X')
		res += ft_puthexa(va_arg(lst, void *), s[i]);
	else if (s[i] == '%')
		res += ft_putchar(s[i]);
	return (res);
}

int	ft_printf(const char *s, ...)
{
	int		res;
	va_list	lst;
	int		i;

	i = 0;
	res = 0;
	va_start(lst, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			res += ft_check_args(lst, s, i);
		}
		else
		{
			res += ft_putchar(s[i]);
		}
		i++;
	}
	va_end(lst);
	return (res);
}
