/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbulut <fbulut@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:33:18 by fbulut            #+#    #+#             */
/*   Updated: 2022/02/11 11:30:01 by fbulut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char str)
{
	return (write(1, &str, 1));
}

int	ft_abs(int data)
{
	if (data < 0)
	{
		ft_putchar('-');
		if (data == -2147483648)
			return (ft_convert(2147483648, "0123456789") + 1);
		return (ft_convert(-data, "0123456789") + 1);
	}
	return (ft_convert(data, "0123456789"));
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putstr(char *c)
{
	if (!c)
		return (ft_putstr("(null)"));
	return (write(1, c, ft_strlen(c)));
}

int	ft_convert(size_t data, char *base)
{
	int			len;
	static char	str[50];
	char		*ptr;

	len = ft_strlen(base);
	ptr = &str[49];
	*ptr = '\0';
	*--ptr = base[data % len];
	data = data / len;
	while (data != 0)
	{
		*--ptr = base[data % len];
		data = data / len;
	}
	return (ft_putstr(ptr));
}
