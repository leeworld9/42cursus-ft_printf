/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uxX.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:57:28 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/16 05:35:43 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

static char ft_uppercase(char c)
{
	if ('a' <= c && 'z' >= c)
		c = c - 'a' + 'A';
	return (c);
}

static void hex_print(unsigned int num, char format)
{
	char remain;

	if (num / 16 != 0)
	{	
		if (format == 'X')
			remain = ft_uppercase("0123456789abcdef"[num % 16]);
		else
			remain = "0123456789abcdef"[num % 16];
		hex_print(num / 16 , format);
		ft_putchar_fd(remain, 1);
	}
	else
	{
		if (format == 'X')
			remain = ft_uppercase("0123456789abcdef"[num]);
		else
		remain = "0123456789abcdef"[num];
		ft_putchar_fd(remain, 1);
	}
}

void ft_printf_uxX(va_list ap, char *target, int i)
{
	if (target[i] == 'u')
		ft_putstr_fd(ft_itoa(va_arg(ap, unsigned int)), 1);
	else if (target[i] == 'x')
		hex_print(va_arg(ap, unsigned int), 'x');
	else if (target[i] == 'X')
		hex_print(va_arg(ap, unsigned int), 'X');	
}