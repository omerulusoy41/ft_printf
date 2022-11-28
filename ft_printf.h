/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oulusoy <oulusoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:12:20 by oulusoy           #+#    #+#             */
/*   Updated: 2022/11/28 21:18:40 by oulusoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putstr(char *arr);
int	ft_len_num(long nb, int base, int len);
int	ft_d(int nb, int sum);
int	ft_uint(unsigned int nb);
int	ft_rec_hex(unsigned long nb, char x);
int	ft_calculate(char c, va_list args);
int	ft_printf(const char *arr, ...);

#endif
