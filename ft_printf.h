/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 10:51:59 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/16 17:08:35 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

# define FT_SEPECIFIER "cspdiuxX%"
# define FT_FLAG "-0"

///  `헤더`와 `라이브러리(.a)` 차이
// 출처 : https://linuxism.ustd.ip.or.kr/344
// 라이브러리를 사용하기 위해서는 해당 라이브러리의 헤더파일이 있어야합니다. 
// 그래야지만 링커가 알아먹을수 있는 심볼네임을 컴파일러가 만들어내기 때문입니다.
# include "./libft/libft.h"

typedef struct	s_printf
{
	char		*tag;
	char		flag;
	int			width;
	int			presision;
	size_t		len;
}				t_printf;

int ft_printf(const char *format, ...);

//test
void ft_printf_c(va_list ap, char *target, int i);
void ft_printf_s(va_list ap, char *target, int i);
void ft_printf_p(va_list ap, char *target, int i);
void ft_printf_di(va_list ap, char *target, int i);
void ft_printf_uxX(va_list ap, char *target, int i);

//utils
void fill_chr(int max, int i, char *result, char chr);
void fill_result(int max, int i, char *result, char *param);
int	find_chr_idx(char *str, char c);
int abs_convert(int num);
void *left_sort(char *result, int max);

#endif