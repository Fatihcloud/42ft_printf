/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbulut <fbulut@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:09:11 by fbulut            #+#    #+#             */
/*   Updated: 2022/02/10 21:46:14 by fbulut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	la_gardas(char a, va_list macro)
{
	if (a == 'c')
		return (ft_putchar(va_arg(macro, int)));
	if (a == 's')
		return (ft_putstr(va_arg(macro, char *)));
	if (a == 'p')
	{
		ft_putstr("0x");
		return (ft_convert(
				va_arg(macro, unsigned long), "0123456789abcdef") + 2);
	}
	if (a == 'u')
		return (ft_convert(va_arg(macro, unsigned int), "0123456789"));
	if (a == '%')
		return (ft_putchar('%'));
	if (a == 'd' || a == 'i')
		return (ft_abs(va_arg(macro, int)));
	if (a == 'x')
		return (ft_convert(va_arg(macro, unsigned int), "0123456789abcdef"));
	if (a == 'X')
		return (ft_convert(va_arg(macro, unsigned int), "0123456789ABCDEF"));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	macro;
	int		a;
	int		b;

	va_start(macro, str);
	a = 0;
	b = 0;
	while (str[a])
	{
		if (str[a] == '%')
		{
			b += la_gardas(str[a + 1], macro);
			a++;
		}
		else
			b += write(1, &str[a], 1);
		a++;
	}
	va_end(macro);
	return (b);
}
