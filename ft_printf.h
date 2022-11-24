/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oulusoy <oulusoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:12:20 by oulusoy           #+#    #+#             */
/*   Updated: 2022/11/24 15:56:44 by oulusoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_putchar(char c);
int	ft_putstr(char *arr);
int	ft_len_num(long nb, int base, int len);
int	ft_rec_num(long nb, int base, char x);
int	ft_calculate(char c, va_list args, long value);
int	ft_printf(const char *arr, ...);

#endif