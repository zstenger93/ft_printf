/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:31:55 by zstenger          #+#    #+#             */
/*   Updated: 2022/11/07 13:42:46 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define HEX_LC "0123456789abcdef"
# define HEX_UC "0123456789ABCDEF"

int		ft_printf(const char *format, ...);

//utils
int		ft_check_format(va_list arg, int type, int *str_len);
void	ft_print_hex(unsigned long number, char *hex_format, int *str_len);
void	ft_putchar(char c, int *str_len);
void	ft_putstr(char *s, int *str_len);
void	ft_putnbr(long long int number, int *str_len);

#endif