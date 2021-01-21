/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:57:36 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/21 13:40:42 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//https://stdbc.tistory.com/59
//https://m.blog.naver.com/ruvendix/220891854070
//https://www.cplusplus.com/reference/cstdio/printf/?kw=printf

static void get_flag(t_printf *data)
{
	char *tmp;
	int pres_idx;
	int i;

	i = 0;
	pres_idx = find_chr_idx(data->tag, '.');
	tmp = (pres_idx != -1) ? ft_substr(data->tag, 0, pres_idx) : data->tag;
	while (tmp[i] != '\0')
	{
		if (ft_strchr(FT_FLAG, tmp[i]) != NULL)
		{
			if ((data->flag) == '-')
				break ;
			data->flag = tmp[i];
		}
		i++;
	}
	if (pres_idx != -1)
		free(tmp);
}

static void get_width(va_list ap, t_printf *data)
{
	int i;
	int pres_idx;
	char *tmp;
	int argument;

	i = 0;
	if (ft_strchr(data->tag, '.'))
	{
		pres_idx = find_chr_idx(data->tag, '.');
		if (pres_idx != -1)
		{ 
			tmp = ft_substr(data->tag, 0, pres_idx);
			if (ft_strchr(tmp, '*'))
			{
				argument = va_arg(ap, int);
				if(argument < 0)
					data->flag = '-';
				data->width = (int)abs_convert(argument);
			}
			else
			{
				while (tmp[i] != '\0' && ft_strchr(FT_FLAG, *(tmp + i)))
					i++;
				data->width = ft_atoi(tmp + i);
			}
			free(tmp);		
		}
	}
	else
	{
		if (ft_strchr(data->tag, '*'))
		{
			argument = va_arg(ap, int);
			if(argument < 0)
				data->flag = '-';
			data->width = (int)abs_convert(argument);
		}
		else
		{
			while (ft_strchr(FT_FLAG, *(data->tag + i)))
				i++;
			data->width = ft_atoi(data->tag + i);
		}
	}
}


static void get_presision(va_list ap, t_printf *data)
{
	char *tmp;
	int pres_idx;
	int pres_size;
	int i;

	i = 0;
	pres_idx = find_chr_idx(data->tag, '.');
	if (pres_idx != -1 && !ft_strchr(FT_SEPECIFIER, data->tag[pres_idx + 1])) // %5.2d
	{ 
		pres_size = ft_strlen(data->tag) - pres_idx - 1;
		tmp = ft_substr(data->tag, pres_idx + 1, pres_size);
		if (tmp[i] != '\0' && ft_strchr(tmp, '*'))
		{
			data->presision = va_arg(ap, int);
			if (data->presision == 0)
				data->presision = -1;
			else if (data->presision < 0)
				data->presision = 0;
		}
		else
		{
			while(tmp[i] != '\0' && ft_strchr(FT_FLAG, tmp[i]))
				i++;
			data->presision = ft_atoi(tmp + i); 
			if (data->presision <= 0)
				data->presision = -1; // 에러 (예외처리 필요)
		}
	}
	else if (pres_idx != -1)  //%5.d
		data->presision = -1;
	else //%5d
		data->presision = 0;
	if (pres_idx != -1 && data->tag[pres_idx + 2] != '\0')
		free(tmp);
}

static int show_result(t_printf *data)
{
	char *param_abs;
	int param_len;
	char *result;

	param_abs = ft_ltoa(abs_convert(data->param));
	param_len = ft_strlen(param_abs); 
	if (data->presision >= data->width)
		data->max_len = ((data->presision > param_len) ? data->presision : param_len);
	else
		data->max_len = ((data->width > param_len) ? data->width : param_len);

	if (data->presision == data->max_len || param_len == data->max_len)
		data->max_len += data->minus;
		
	if ((result = (char *)malloc(sizeof(char) * (data->max_len + 1))) == NULL)
		return (0);
	ft_memset(result, '_', data->max_len);
	result[data->max_len] = '\0';

	// 예외처리
	if (data->flag == '0' && data->presision == 0)
		fill_chr(data, data->width, result, '0');
	else
	{
		fill_chr(data, data->width, result, ' ');
		fill_chr(data, data->presision, result, '0');
	}

	if (data->param == 0) // 인자 0 일때 예외처리
	{
		if (data->presision == -1 && data->width != 0)
			fill_result(data, result, "\0");
		else if (data->presision == -1 && data->max_len == 1) // 여기가 문제야 문제
		{
			result[0] = '\0';
			data->max_len--;
		}
		else if (data->presision == -1)
			fill_result(data, result, "\0");
		else if (data->presision == 0)
			fill_result(data, result, "0");
	}
	else
		fill_result(data, result, param_abs);

	if (data->flag == '-')
		left_sort(result, data->max_len);

	//printf(">>>>>>>>flag : %c\n", data->flag);
	// printf(">>>>>>>>param_abs : |%s|\n", param_abs);
	// printf(">>>>>>>>param : %lld\n", abs_convert(data->param));
	// printf(">>>>>>>>width : %d\n", data->width);
	// printf(">>>>>>>>presision : %d\n", data->presision);
	// printf(">>>>>>>>max_len : %d\n", data->max_len);
	// printf(">>>>>>>>param_len : %d\n", param_len);

	ft_putstr_fd(result, 1);

	free(param_abs);
	free(result);
	return (data->max_len); 
}


int ft_printf_di(va_list ap, char *target, int i)
{
	t_printf *data;
	int len;

	len = 0;
	data = (t_printf *)malloc(sizeof(t_printf));
	data->tag = ft_substr(target, 1, i);
	data->flag = '\0';
	data->width = 0;
	data->presision = -1;

	get_flag(data);
	get_width(ap, data);
	get_presision(ap, data);
	data->param = va_arg(ap, int);
	data->minus = (data->param < 0) ? 1 : 0;
	
	len += show_result(data);
	//len += ft_strlen(param);


	free(data->tag);
	free(data);
	return (len);
}