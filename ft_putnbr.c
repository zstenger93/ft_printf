/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:13:04 by zstenger          #+#    #+#             */
/*   Updated: 2022/11/10 18:06:21 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

/*
if the number is smaller than 0 print the minus sign and
take it off from the number by multiplying it by -1
and then print it after te sign with the 2nd if or the 
else statement
*/
void	ft_putnbr(long int number, int *input_len)
{
	if (number < 0)
	{
		ft_putchar('-', input_len);
		number *= -1;
	}
	if (number > 9)
	{
		ft_putnbr(number / 10, input_len);
		ft_putchar(number % 10 + '0', input_len);
	}
	else
		ft_putchar(number + '0', input_len);
}
