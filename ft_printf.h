/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:31:55 by zstenger          #+#    #+#             */
/*   Updated: 2022/11/10 15:48:27 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define HEX_LC "0123456789abcdef"
# define HEX_UC "0123456789ABCDEF"

int		ft_printf(const char *format, ...);

//utils
int		ft_check_format(va_list args, char type_specifier, int *input_len);
void	ft_print_hex(unsigned long number, char *hex_format, int *input_len);
void	ft_putchar(char c, int *input_len);
void	ft_putstr(char *str, int *input_len);
void	ft_putnbr(long int number, int *input_len);

#endif