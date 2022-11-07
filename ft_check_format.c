/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:40:01 by zstenger          #+#    #+#             */
/*   Updated: 2022/11/07 12:03:26 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

/*
checking for the type of the format in the arguments and
applies the correct function to print out the result
0x is the prefix for hexadecimals and used it to get the same
output as printf while printing pointers

• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.
*/
int	ft_check_format(va_list arg, int type, int *str_len)
{
	if (type == '%')
		ft_putchar('%', str_len);
	else if (type == 'c')
		ft_putchar(va_arg(arg, int), str_len);
	else if (type == 's')
		ft_putstr(va_arg(arg, char *), str_len);
	else if (type == 'p')
	{
		ft_putstr("0x", str_len);
		ft_print_hex(va_arg(arg, unsigned long), HEX_LC, str_len);
	}
	else if (type == 'd' || type == 'i')
		ft_putnbr(va_arg(arg, int), str_len);
	else if (type == 'u')
		ft_putnbr(va_arg(arg, unsigned int), str_len);
	else if (type == 'x')
		ft_print_hex(va_arg(arg, unsigned int), HEX_LC, str_len);
	else if (type == 'X')
		ft_print_hex(va_arg(arg, unsigned int), HEX_UC, str_len);
	return (0);
}
