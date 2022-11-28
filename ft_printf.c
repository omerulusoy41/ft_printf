/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oulusoy <oulusoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:12:25 by oulusoy           #+#    #+#             */
/*   Updated: 2022/11/28 22:00:55 by oulusoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_rec_hex(unsigned long nb, char x)
{
	if (nb == (unsigned long long)-0x7fffffffffffffffL - 1)
		return (ft_putstr("8000000000000000"));
	if (nb == 0xffffffffffffffffUL)
		return (ft_putstr("ffffffffffffffff"));
	if (nb >= 16)
		ft_rec_hex(nb / 16, x);
	if (x == 'x')
		ft_putchar("0123456789abcdef"[nb % 16]);
	else
		ft_putchar("0123456789ABCDEF"[nb % 16]);
	return (ft_len_num(nb, 16, 0));
}

int	ft_uint(unsigned int nb)
{
	if (nb >= 10)
		ft_uint (nb / 10);
	ft_putchar("0123456789"[nb % 10]);
	return (ft_len_num(nb, 10, 0));
}

int	ft_printf(const char *arr, ...)
{
	int		sum;
	va_list	args;

	va_start(args, arr);
	sum = 0;
	while (*arr != '\0')
	{
		if (*arr == '%')
			sum += ft_calculate(*(++arr), args);
		else
			sum += ft_putchar(*arr);
		arr++;
	}
	va_end(args);
	return (sum);
}
#include <limits.h>
#include <stdio.h>
int main(){
    int c = -2147483648;
    printf("%d\n",ft_printf("123 %c %d %i %x %X %p %u %s %%\n",'A',-2147483648,89,1002,1002,ULONG_MAX,-12,"yumurta"));
    printf("%d\n",printf("123 %c %d %i %x %X %p %u %s %%\n",'A',-2147483648,89,1002,1002,ULONG_MAX,-12,"yumurta"));
}