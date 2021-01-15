/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 10:51:59 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/15 16:01:22 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

///  `헤더`와 `라이브러리(.a)` 차이
// 출처 : https://linuxism.ustd.ip.or.kr/344
// 라이브러리를 사용하기 위해서는 해당 라이브러리의 헤더파일이 있어야합니다. 
// 그래야지만 링커가 알아먹을수 있는 심볼네임을 컴파일러가 만들어내기 때문입니다.
# include "./libft/libft.h"

int ft_printf(const char *format, ...);

//test
void ft_printf_c(va_list ap);
void ft_printf_s(va_list ap);
void ft_printf_p(va_list ap);
void ft_printf_di(va_list ap);
void ft_printf_uxX(va_list ap, char flag);

#endif