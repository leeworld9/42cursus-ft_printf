/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:57:34 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/18 20:33:34 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int addr_print(long long addr, int len)
{
	char remain;

	if (addr / 16 != 0)
	{
		remain = "0123456789abcdef"[addr % 16];
		len += addr_print((addr / 16), len);
		ft_putchar_fd(remain, 1);
	}
	else
	{
		remain = "0123456789abcdef"[addr];
		ft_putchar_fd(remain, 1);
	}
	len++;
	return (len);
}

int ft_printf_p(va_list ap)
{
	void *tmp;
	long long addr;
	int len;
	
	len = 0;
	tmp = va_arg(ap, void *);
	if (tmp != NULL)
	{
		addr = (long long)tmp;
		ft_putstr_fd("0x", 1);
		len += (addr_print(addr, len) + 2);

	}
	else
		ft_putstr_fd("(nil)", 1); // 갯수에 포함해야하나?? 일단 보류 (리눅스랑 맥이랑 결과 다르다고 함)
	return (len);
}