/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uxX.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:57:28 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/20 12:21:40 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

static char ft_uppercase(char c)
{
	if ('a' <= c && 'z' >= c)
		c = c - 'a' + 'A';
	return (c);
}

static int hex_print(unsigned int num, char format, int len)
{
	char remain;

	if (num / 16 != 0)
	{	
		if (format == 'X')
			remain = ft_uppercase("0123456789abcdef"[num % 16]);
		else
			remain = "0123456789abcdef"[num % 16];
		len += hex_print(num / 16 , format, len);
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
	len++;
	return (len);
}

int ft_printf_uxX(va_list ap, char *target, int i)
{
	char *tmp;
	long long num;
	int len;

	len = 0;
	if (target[i] == 'u')
	{
		num = va_arg(ap, long long);
		while (num < 0 || num > UINT_MAX)
		{
			if (num > UINT_MAX)
				num = num - UINT_MAX - 1;
			else if (num < 0)
				num = UINT_MAX + num + 1;
		}
		tmp = ft_ltoa(num);
		ft_putstr_fd(tmp, 1);
		len += ft_strlen(tmp);
		free(tmp);
	}	
	else if (target[i] == 'x')
		len += hex_print(va_arg(ap, unsigned int), 'x', len);
	else if (target[i] == 'X')
		len += hex_print(va_arg(ap, unsigned int), 'X', len);
	return (len);
}