/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 10:51:59 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/21 17:57:26 by dohelee          ###   ########.fr       */
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

# include "./libft/libft.h"

typedef struct	s_printf
{
	char		*tag;
	char		flag;
	int			width;
	int			pres;
	int			minus;
	long long	param; //max값 처리 필요?
	int			max_len;
}				t_printf;

int ft_printf(const char *format, ...);

//test
int ft_printf_c(va_list ap);
int ft_printf_s(va_list ap);
int ft_printf_p(va_list ap);
int ft_printf_di(va_list ap, char *target, int i);
int ft_printf_uxX(va_list ap, char *target, int i);

//common utils
int	find_chr_idx(char *str, char c);
long long abs_convert(long long num);

//di utils
char *flag_bypass(char *str);
void fill_chr(t_printf *data, int  i, char *result, char chr);
void fill_result(t_printf *data, char *result, char *param);
void left_sort(char *result, int max_len);
void get_maxlen(t_printf *data, int param_len);
int	zero_flagchk(va_list ap, t_printf *data);


//exception
char *di_exception(t_printf *data, char *result, char *param_abs);

//etc
char *ft_ltoa(long long n);

#endif