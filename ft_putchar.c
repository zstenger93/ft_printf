/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:11:45 by zstenger          #+#    #+#             */
/*   Updated: 2022/11/10 15:47:25 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

/*
writing chars and calculating the length of the string
*/
void	ft_putchar(char c, int *input_len)
{
	*input_len += write(1, &c, 1);
}
