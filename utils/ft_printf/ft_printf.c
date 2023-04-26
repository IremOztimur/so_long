/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:38:58 by ioztimur          #+#    #+#             */
/*   Updated: 2023/02/17 02:05:20 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len(unsigned long nbr, char *base, int class, int base_len)
{
	int	i;
	int	len;

	len = 0;
	i = -1;
	if (class == 1)
	{
		if (!base)
			return (write(1, "(null)", 6));
		else
			while (base[++i])
				len += write(1, &base[i], 1);
		return (len);
	}
	if (class == 3)
		len += write(1, "0x", 2);
	if (class == 2 && (int)(nbr) < 0)
	{
		len += write(1, "-", 1);
		nbr *= -1;
	}
	if ((nbr / base_len) != 0)
		len += ft_len((nbr / base_len), base, 0, base_len);
	len += write(1, &base[nbr % base_len], 1);
	return (len);
}

int	ft_format(char c, va_list a)
{
	char	chr;

	if (c == 'c')
	{
		chr = va_arg(a, int);
		return (write(1, &chr, 1));
	}
	if (c == 's')
		return (ft_len(0, va_arg(a, char *), 1, 0));
	if (c == 'd' || c == 'i')
		return (ft_len(va_arg(a, int), "0123456789", 2, 10));
	if (c == 'p')
		return (ft_len(va_arg(a, unsigned long), "0123456789abcdef", 3, 16));
	if (c == 'u')
		return (ft_len(va_arg(a, unsigned int), "0123456789", 0, 10));
	if (c == 'x')
		return (ft_len(va_arg(a, unsigned int), "0123456789abcdef", 0, 16));
	if (c == 'X')
		return (ft_len(va_arg(a, unsigned int), "0123456789ABCDEF", 0, 16));
	if (c == '%')
		return (write(1, &c, 1));
	else
		return (write(1, &c, 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	a;

	va_start(a, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
			len += ft_format(str[++i], a);
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(a);
	return (len);
}
