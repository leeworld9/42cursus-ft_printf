/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_exception.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:50:29 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/25 14:52:57 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*di_exception(t_printf *data, char *result, char *param_abs)
{
	if (data->flag == '0' && data->prec == 0)
		fill_chr(data, data->width, result, '0');
	else
	{
		fill_chr(data, data->width, result, ' ');
		fill_chr(data, data->prec, result, '0');
	}
	if (data->i_param == 0)
	{
		if (data->prec == -1 && data->width != 0)
			fill_result(data, result, "\0");
		else if (data->prec == -1 && data->max_len == 1)
		{
			result[0] = '\0';
			data->max_len--;
		}
		else if (data->prec == 0)
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
	if (data->flag == '0' && data->prec == 0)
		fill_chr(data, data->width, result, '0');
	else
		fill_chr(data, data->max_len, result, ' ');
	if (data->prec == -1 || data->prec > 0)
	{
		if (data->max_len != 0 && data->prec != -1)
			fill_s_result(data, result, data->str_param);
	}
	else
		fill_result(data, result, data->str_param);
	if (data->flag == '-')
		left_sort(result, data->max_len);
	return (result);
}

char	*ux_exception(t_printf *data, char *result, char *param)
{
	if (data->flag == '0' && data->prec == 0)
		fill_chr(data, data->width, result, '0');
	else
	{
		fill_chr(data, data->width, result, ' ');
		fill_chr(data, data->prec, result, '0');
	}
	if (data->prec == -1)
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
	if (data->flag == '0' && data->prec == 0)
		fill_chr(data, data->width, result, '0');
	else
		fill_chr(data, data->max_len, result, ' ');
	fill_result(data, result, param);
	if (data->flag == '-')
		left_sort(result, data->max_len);
	return (result);
}

char	*c_exception(t_printf *data, char *result, char *param)
{
	// if (data->flag == '0')
	// 	fill_chr(data, data->width, result, '0');
	// else
		fill_chr(data, data->max_len, result, ' ');
	result[data->max_len - 1] = param[0];
	if (data->flag == '-')
		left_sort(result, data->max_len);
	return (result);
}
