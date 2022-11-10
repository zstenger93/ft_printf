/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:53:13 by zstenger          #+#    #+#             */
/*   Updated: 2022/11/10 16:15:25 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

/*
no input, return null
while there is input if no % found prints out the input else looks for format
types, applies the right one and then prints the result.
*/
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		index;
	int		*input_len;
	int		output;

	va_start(args, format);
	output = 0;
	index = 0;
	input_len = &output;
	if (!format)
		return (0);
	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			index++;
			ft_check_format(args, format[index], input_len);
		}
		else
			output += write(1, &format[index], 1);
		index++;
	}
	va_end(args);
	return (output);
}
