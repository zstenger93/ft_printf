/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:11:45 by zstenger          #+#    #+#             */
/*   Updated: 2022/11/07 13:43:20 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

/*
writing chars and calculating the length of the string
*/
void	ft_putchar(char c, int *str_len)
{
	*str_len += write(1, &c, 1);
}
