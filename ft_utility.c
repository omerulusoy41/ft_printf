/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oulusoy <oulusoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:25:44 by oulusoy           #+#    #+#             */
/*   Updated: 2022/11/24 16:20:42 by oulusoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *arr)
{
	int	sum;

	if (!arr)
		return (write(1, "(null)", 6));
	sum = -1;
	while (arr[++sum])
		ft_putchar(arr[sum]);
	return (sum);
}

int	ft_len_num(long nb, int base, int len)
{
	while (nb > 0 && ++len)
		nb /= base;
	return (len);
}

int	ft_rec_num(long nb, int base, char x)
{
	if (nb >= base)
		ft_rec_num (nb / base, base, x);
	if (x == 'x')
		ft_putchar("0123456789abcdef"[nb % base]);
	else
		ft_putchar("0123456789ABCDEF"[nb % base]);
	return (ft_len_num(nb, base, 0));
}

int	ft_calculate(char c, va_list args,long value)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 'd' || c == 'i')
	{
		value = va_arg(args, long);
		if ((int)value < 0)
			return (ft_putchar('-') + ft_rec_num(-1 * ((int)value), 10, 'x'));
		else
			return ft_rec_num(value, 10, 'x');
	}
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'p')
		return (ft_putstr("0x") + ft_rec_num(va_arg(args, unsigned long long), 16, 'x'));
	else if (c == 'X' || c == 'x')
		return (ft_rec_num(va_arg(args, unsigned int), 16, c));
	else if (c == 'u')
		return (ft_rec_num(va_arg(args, unsigned int), 10, 'x'));
	return (-1);
}
