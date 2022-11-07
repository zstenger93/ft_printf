/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:53:13 by zstenger          #+#    #+#             */
/*   Updated: 2022/11/07 13:47:04 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

/*
while there is input if no % found prints out the input else looks for format
types, applies the right one and then prints the result.
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
			ft_check_format(arg, format[z], str_len);
		}
		else
			len += write(1, &format[z], 1);
		z++;
	}
	va_end(arg);
	return (len);
}
