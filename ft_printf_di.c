/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:57:36 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/18 20:13:43 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf_di(va_list ap)
{
	char *tmp;
	int len;

	len = 0;
	tmp = ft_itoa(va_arg(ap, int));
	ft_putstr_fd(tmp, 1);
	len += ft_strlen(tmp);
	free(tmp);
	return (len);
}