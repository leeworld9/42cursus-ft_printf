/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 10:50:59 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/25 14:45:32 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	find_specifier(char *target)
{
	int i;

	i = 1;
	while (target[i] != '\0')
	{
		if (ft_strchr(FT_SEPECIFIER, target[i]))
			break ;
		i++;
	}
	if ((int)ft_strlen(target) == i)
		return (-1);
	return (i);
}

static int	print_format(char *target, va_list ap, int i)
{
	int len;

	len = 0;
	if (target[i] == 'c')
		len += ft_printf_c(ap, target, i);
	else if (target[i] == 's')
		len += ft_printf_s(ap, target, i);
	else if (target[i] == 'p')
		len += ft_printf_p(ap, target, i);
	else if (target[i] == 'd' || target[i] == 'i')
		len += ft_printf_di(ap, target, i);
	else if (target[i] == 'u' || target[i] == 'x' || target[i] == 'X')
		len += ft_printf_ux(ap, target, i);
	else if (target[i] == '%')
	{
		ft_putstr_fd("%", 1);
		len++;
	}
	return (len);
}

static int	spec_print(const char *format)
{
	char	*tmp;
	int		len;

	len = 0;
	tmp = ft_substr(format, 0, find_chr_idx((char *)format, '%'));
	len += ft_strlen(tmp);
	ft_putstr_fd(tmp, 1);
	free(tmp);
	return (len);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	char	*target;
	int		len;

	len = 0;
	va_start(ap, format);
	while (true)
	{
		if ((target = ft_strchr((char *)format, '%')) != NULL)
		{
			len += spec_print(format);
			if ((i = find_specifier(target)) > 0)
				len += print_format(target, ap, i);
			format = target + i + 1;
		}
		else
		{
			len += ft_strlen((char *)format);
			ft_putstr_fd((char *)format, 1);
			break ;
		}
	}
	va_end(ap);
	return (len);
}
