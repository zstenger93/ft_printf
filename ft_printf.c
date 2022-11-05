/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:53:13 by zstenger          #+#    #+#             */
/*   Updated: 2022/11/05 16:13:41 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

/*
while there is input if no % prints out the input else looks for format
specifiers and applies the right one then returns the result.
*/
int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		z;
	int		*str_len;
	int		len;
	
	va_start(arg, format);
	len = 0;
	z = 0;
	str_len = &len;
	if (!format[z])
		return (0);
	while (format[z])
	{
		if (format[z] == '%')
		{
			z++;
			ft_check_format(format, arg, z, str_len);
		}
		else
		{
			len += write(1, &format[z], 1);
		}
			
		z++;
	}
	va_end(arg);
	return (len);
}

int	ft_check_format(char const *str, va_list arg, int index, int *str_len)
{
	if (str[index] == '%')
		ft_putchar('%', str_len);
	else if (str[index] == 'c')
		ft_putchar(va_arg(arg, int), str_len);
	else if (str[index] == 's')
		ft_putstr(va_arg(arg, char *), str_len);
	else if (str[index] == 'p')
	{
		ft_putstr("0x", str_len);
		ft_print_hex(va_arg(arg, unsigned long), HEX_LC, str_len);
	}
	else if (str[index] == 'd' || str[index] == 'i')
		ft_putnbr(va_arg(arg, int), str_len);
	else if (str[index] == 'u')
		ft_putnbr(va_arg(arg, unsigned int), str_len);
	else if (str[index] == 'x')
		ft_print_hex(va_arg(arg, unsigned int), HEX_LC, str_len);
	else if (str[index] == 'X')
		ft_print_hex(va_arg(arg, unsigned int), HEX_UC, str_len);
	return (0);
}

void	ft_print_hex(unsigned long number, char *hex_format, int *str_len)
{
	if (number > 255)
	{
		ft_print_hex((number / 16), hex_format, str_len);
		ft_putchar(hex_format[number % 16], str_len);
	}
	else
	{
		if (number >= 16)
		{
			ft_putchar(hex_format[number / 16], str_len);
			ft_putchar(hex_format[number % 16], str_len);
		}
		else
			ft_putchar(hex_format[number % 16], str_len);
	}
}

void	ft_putchar(char c, int *str_len)
{
	*str_len += write(1, &c, 1);		
}

void	ft_putnbr(long long int n, int *str_len)
{
	if (n < 0)
	{
		ft_putchar('-', str_len);
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, str_len);
		ft_putchar(n % 10 + '0', str_len);
	}
	else
		ft_putchar(n + '0', str_len);
}

void	ft_putstr(char *s, int *str_len)
{
	int	len;

	if (!s)
	{
		ft_putstr("(null)", str_len);
		return ;
	}
	len = 0;
	while (s[len] != '\0')
	{
		ft_putchar(s[len], str_len);
		len++;
	}
}

// #include <stdio.h>
// int main(void)
// {
// 	ft_printf("%%");
// 	printf("\n");
// 	printf("%%");
// 	printf("\n");
// }