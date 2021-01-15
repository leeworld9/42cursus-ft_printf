/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:57:34 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/15 14:30:54 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void addr_print(long long addr)
{
	char remain;

	if (addr / 16 != 0)
	{
		remain = "0123456789abcdef"[addr % 16];
		addr_print(addr / 16);
		ft_putchar_fd(remain, 1);
	}
	else
	{
		remain = "0123456789abcdef"[addr];
		ft_putchar_fd(remain, 1);
	}
}

void ft_printf_p(va_list ap)
{
	long long addr;
	
	addr = (long long)va_arg(ap, void *);
	ft_putstr_fd("0x", 1);
	addr_print(addr);
}