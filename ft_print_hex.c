/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:46:37 by zstenger          #+#    #+#             */
/*   Updated: 2022/11/08 13:36:10 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

/*
Divide the decimal number by 16.   Treat the division as an integer division.
Write down the remainder (in hexadecimal)
Divide the result again by 16.  Treat the division as an integer division.
repeat until the result is 0
The hex value is the digit sequence of the remainders from the last to first.

hex table is from 0 - 255.
if bigger number > 255 than do the division with the logic in mind mentinoned
at the start.
if 16 < number < 256 just calculate the first piece and the remainder is the
second one.
if the number is smaller than 16 which is the amount of hex chars then
write the reminder.

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
