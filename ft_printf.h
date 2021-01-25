/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 10:51:59 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/25 21:05:14 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define FT_SEPECIFIER "cspdiuxX%"
# define FT_FLAG "-0"

# include "./libft/libft.h"

typedef struct			s_printf
{
	char				*tag;
	char				flag;
	int					width;
	int					prec;
	int					minus;
	int					i_param;
	unsigned long long	ull_param;
	char				*str_param;
	void				*void_p;
	int					max_len;
}						t_printf;

int						ft_printf(const char *format, ...);

int						ft_printf_c(va_list ap, char *target, int i);
int						ft_printf_s(va_list ap, char *target, int i);
int						ft_printf_p(va_list ap, char *target, int i);
int						ft_printf_di(va_list ap, char *target, int i);
int						ft_printf_ux(va_list ap, char *target, int i);
int						ft_printf_percent(va_list ap, char *target, int i);

void					get_flag(t_printf *data);
void					get_width(va_list ap, t_printf *data);
void					get_prec(va_list ap, t_printf *data);
char					*flag_bypass(char *str);
int						zero_flagchk(va_list ap, t_printf *data);

int						find_chr_idx(char *str, char c);
long long				abs_convert(long long num);
void					fill_chr(t_printf *data, int i, char *result, char chr);
void					fill_result(t_printf *data, char *result, char *param);
void					left_sort(char *result, int max_len);

void					get_di_maxlen(t_printf *data, int param_len);

void					get_s_maxlen(t_printf *data, int param_len);
void					fill_s_result(t_printf *data, char *result, char *param);

void					get_ux_maxlen(t_printf *data, int param_len);
void					reverse_arr(char *arr);

void					get_c_maxlen(t_printf *data, int param_len);
void					ft_c_putstr_fd(t_printf *data, char *result, int fd);

void					get_p_maxlen(t_printf *data, int param_len);

char					*di_exception(t_printf *data, char *result, char *param_abs);
char					*s_exception(t_printf *data, char *result);
char					*ux_exception(t_printf *data, char *result, char *param);
char					*p_exception(t_printf *data, char *result, char *param);
char					*c_exception(t_printf *data, char *result, char *param);

#endif
