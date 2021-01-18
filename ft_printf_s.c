/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:57:31 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/18 20:05:49 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf_s(va_list ap)
{
	char *tmp;
	int len;

	len = 0;
	tmp = va_arg(ap, char *);
	if (tmp != NULL)
	{
		ft_putstr_fd(tmp, 1);
		len += ft_strlen(tmp);
	}
	else
		ft_putstr_fd("(null)", 1);
	return (len);
}