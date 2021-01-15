/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uxX.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:57:28 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/15 15:52:23 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

static char ft_uppercase(char c)
{
	if ('a' <= c && 'z' >= c)
		c = c - 'a' + 'A';
	return (c);
}

static void hex_print(unsigned int num, char flag)
{
	char remain;

	if (num / 16 != 0)
	{	
		if (flag == 'X')
			remain = ft_uppercase("0123456789abcdef"[num % 16]);
		else
			remain = "0123456789abcdef"[num % 16];
		hex_print(num / 16 , flag);
		ft_putchar_fd(remain, 1);
	}
	else
	{
		if (flag == 'X')
			remain = ft_uppercase("0123456789abcdef"[num]);
		else
		remain = "0123456789abcdef"[num];
		ft_putchar_fd(remain, 1);
	}
}


void ft_printf_uxX(va_list ap, char flag)
{
	if (flag == 'u')
		ft_putstr_fd(ft_itoa(va_arg(ap, unsigned int)), 1);
	else if (flag == 'x')
		hex_print(va_arg(ap, unsigned int), 'x');
	else if (flag == 'X')
		hex_print(va_arg(ap, unsigned int), 'X');
	
}