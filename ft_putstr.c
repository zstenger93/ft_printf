/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:13:51 by zstenger          #+#    #+#             */
/*   Updated: 2022/11/07 13:43:31 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

/*
print out null if no string after the format specifier
or print the length of the string until the terminating
null
*/
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
