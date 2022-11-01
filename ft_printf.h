/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:37:31 by zstenger          #+#    #+#             */
/*   Updated: 2022/11/01 16:50:18 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define HEX_LC "0123456789abcdef"
# define HEX_UC "0123456789ABCDEF"

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *, ...);

void	ft_check_format(char const *str, va_list arg, int index, int arg_len);
void	ft_print_char(va_list arg, int *arg_len);
void	ft_print_int(va_list arg, int *arg_len);
void	ft_print_str(va_list arg, int *arg_len);
void	ft_print_ptr(va_list arg, int *arg_len);
void	ft_print_uint(va_list arg, int *arg_len);
void	ft_print_hex(va_list arg, int *arg_len, char c);

//utils
void	ft_putchar(char c, int base_len);
void	ft_putstr(char *s, int base_len);
void	ft_putnbr(int n, int base_len);
size_t	ft_strlen(char *str);



#endif