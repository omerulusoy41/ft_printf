/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oulusoy <oulusoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:12:25 by oulusoy           #+#    #+#             */
/*   Updated: 2022/11/24 16:07:48 by oulusoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *arr, ...)
{
	int		sum;
	va_list	args;

	va_start(args, arr);
	sum = 0;
	while (*arr != '\0')
	{
		if (*arr == '%')
			sum += ft_calculate(*(++arr), args, 0);
		else
			sum += ft_putchar(*arr);
		arr++;
	}
	va_end(args);
	return (sum);
}
// int main(){
//     int c = 2;
//     printf("%d\n",ft_printf("123 %c %d %i %x %X %p %u %s %%\n",'A',-2147483648,89,1002,1002,&c,-12,"yumurta"));
//     printf("%d\n",printf("123 %c %d %i %x %X %p %u %s %%\n",'A',-2147483648,89,1002,1002,&c,-12,"yumurta"));
// }