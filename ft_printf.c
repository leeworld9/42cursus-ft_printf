/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 10:50:59 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/18 20:31:58 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	find_specifier(char *target)
{
	int i;

	i = 1;/* `%` 제외하고 찾기 */
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

static int print_format(char *target, va_list ap, int i)
{
	int len;

	len = 0;
	if (target[i] == 'c')
		len += ft_printf_c(ap);
	else if (target[i] == 's')
		len += ft_printf_s(ap);
	else if (target[i] == 'p')
		len += ft_printf_p(ap);
	else if (target[i] == 'd' || target[i] == 'i')
		len += ft_printf_di(ap);
	else if (target[i] == 'u' ||target[i] == 'x' || target[i] == 'X')
		len += ft_printf_uxX(ap, target, i);
	else if (target[i] == '%' && i == 1)
	{
		ft_putstr_fd("%", 1);
		len++;
	}
	return (len);
}

/* 기본서식 : %[플래그][폭][.정밀도,길이]서식지정자 */
//            %[flag][width][.precision]서식지정자
// 마지막에 main.c 지우기!!
int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	char	*target;
	char	*tmp;
	int		len;

	i = 0;
	len = 0;
	va_start(ap, format);
	while (true)
	{	
		if ((target = ft_strchr((char *)format, '%')) != NULL) // target은 `%`로 시작하는 문자열
		{
			tmp = ft_substr(format, 0, find_chr_idx((char *)format, '%'));
			len += ft_strlen(tmp);
			ft_putstr_fd(tmp, 1);  // 서식지정자 전 까지 출력
			free(tmp);
			if ((i = find_specifier(target)) > 0) // i는 서식지정자 idx
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