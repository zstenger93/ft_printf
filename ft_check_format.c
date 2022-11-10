/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:40:01 by zstenger          #+#    #+#             */
/*   Updated: 2022/11/10 17:48:51 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

/*
checking for the conversion type with type_specifier of the format in the
arguments and applies the correct function to print out the result
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
int	ft_check_format(va_list args, char type_specifier, int *input_len)
{
	if (type_specifier == '%')
		ft_putchar('%', input_len);
	else if (type_specifier == 'c')
		ft_putchar(va_arg(args, int), input_len);
	else if (type_specifier == 's')
		ft_putstr(va_arg(args, char *), input_len);
	else if (type_specifier == 'p')
	{
		ft_putstr("0x", input_len);
		ft_print_hex(va_arg(args, unsigned long), HEX_LC, input_len);
	}
	else if (type_specifier == 'd' || type_specifier == 'i')
		ft_putnbr(va_arg(args, int), input_len);
	else if (type_specifier == 'u')
		ft_putnbr(va_arg(args, unsigned int), input_len);
	else if (type_specifier == 'x')
		ft_print_hex(va_arg(args, unsigned int), HEX_LC, input_len);
	else if (type_specifier == 'X')
		ft_print_hex(va_arg(args, unsigned int), HEX_UC, input_len);
	return (0);
}
