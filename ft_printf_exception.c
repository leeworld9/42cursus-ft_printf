/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_exception.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:50:29 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/23 07:47:23 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*di_exception(t_printf *data, char *result, char *param_abs)
{
	if (data->param == 0)
	{
		if (data->pres == -1 && data->width != 0)
			fill_result(data, result, "\0");
		else if (data->pres == -1 && data->max_len == 1)
		{
			result[0] = '\0';
			data->max_len--;
		}
		else if (data->pres == -1)
			fill_result(data, result, "\0");
		else if (data->pres == 0)
			fill_result(data, result, "0");
	}
	else
		fill_result(data, result, param_abs);
	if (data->flag == '-')
		left_sort(result, data->max_len);
	return (result);
}

char	*s_exception(t_printf *data, char *result)
{
	//printf("maxlen:%d\n" , data->max_len);
	//반드시 data->pres(==-1, >0)만큼만 출력, (0)일때는 전부 출력
	if (data->pres == -1 || data->pres > 0)
	{
		if (data->max_len != 0 && data->pres != -1)
		{
			fill_s_result(data, result, data->str_param);
		}
	}
	else
		fill_result(data, result, data->str_param);

	if (data->flag == '-')
		left_sort(result, data->max_len);
	return (result);
}


char	*uxX_exception(t_printf *data, char *result, char *param)
{
	// ㅅㅂ 0일때 예외처리 ㅈ 같네
	fill_chr(data, data->pres, result, '0');
	if (data->flag == '0' && data->pres == 0)
		fill_chr(data, data->width, result, '0');
	else if (data->max_len == data->pres)
		fill_chr(data, data->max_len, result, '0');
	else if (data->pres == -1)
	{
		if (data->width > 0 && *param == '0')
		{
			fill_chr(data, data->width, result, ' ');
			return (result);
		}
		else if (data->width == 0 && *param == '0')
		{
			fill_chr(data, data->max_len, result, '\0');
			data->max_len--;
			return (result);
		}
	}	
	fill_result(data, result, param);
	if (data->flag == '-')
		left_sort(result, data->max_len);
	return (result);
}


char	*p_exception(t_printf *data, char *result, char *param)
{
	fill_result(data, result, param);
	if (data->flag == '-')
		left_sort(result, data->max_len);
	return (result);
}
