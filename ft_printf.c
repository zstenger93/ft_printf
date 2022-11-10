/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:53:13 by zstenger          #+#    #+#             */
/*   Updated: 2022/11/10 19:21:15 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

/*
@param format if there is format(input) checks the type of it
if its a plain text, print it out
else checks for the type of conversion and applies it and print the result
and for specifiers which I dont have.
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

/*
int main(void)
{
	char str1[] = "This is the first format specifier#&.';?/!\n";
	ft_printf("MY PRINTF:\n%s", str1);
	printf("ORIGINAL PRINTF:\n%s", str1);

	int i = -2147483648;
	int j = 2147483647;
	int l = 0;
	int	*ptr1;
	int	*ptr2;
	int	*ptr3;
	int	*ptr4;

	ptr1 = &i;
	ptr2 = &j;
	ptr3 = &l;
	ptr4 = NULL;

	ft_printf("MY PRINTF:\n%p\n%p\n%p\n%p\n", ptr1, ptr2, ptr3, ptr4);
	printf("ORIGINAL PRINTF:\n%p\n%p\n%p\n%p\n", ptr1, ptr2, ptr3, ptr4);

	i = -2147483648;
	j = 2147483647;
	l = 0;

	ft_printf("MY PRINTF:\n%d\n%d\n%d\n", i, j, l);
	printf("ORIGINAL PRINTF:\n%d\n%d\n%d\n", i, j, l);

	ft_printf("MY PRINTF:\n%i\n%i\n%i\n", i, j, l);
	printf("ORIGINAL PRINTF:\n%i\n%i\n%i\n", i, j, l);

	unsigned int k;
	
	i = -2147483648;
	j = 0;
	k = 4294967295;

	ft_printf("MY PRINTF:\n%u\n%u\n%u\n", i, j, k);
	printf("ORIGINAL PRINTF:\n%u\n%u\n%u\n", i, j, k);

	i = -2147483648;
	j = 0;
	k = 42949627;
	
	ft_printf("MY PRINTF:\n%x\n%x\n%x\n", i, j, k);
	printf("ORIGINAL PRINTF:\n%x\n%x\n%x\n", i, j, k);

	ft_printf("MY PRINTF:\n%X\n%X\n%X\n", i, j, k);
	printf("ORIGINAL PRINTF:\n%X\n%X\n%X\n", i, j, k);

	ft_printf("MY PRINTF:\n%% %%%% %%\n");
	printf("ORIGINAL PRINTF:\n%% %%%% %%\n");
	
	return (0);
}
*/