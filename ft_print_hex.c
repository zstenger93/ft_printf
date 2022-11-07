/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:46:37 by zstenger          #+#    #+#             */
/*   Updated: 2022/11/07 13:46:57 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

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
