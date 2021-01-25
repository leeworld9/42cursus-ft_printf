/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_exception.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:50:29 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/25 22:23:26 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*di_exception(t_printf *data, char *res, char *p_abs)
{
	if (data->flag == '0' && data->prec == 0)
		fill_chr(data, data->width, res, '0');
	else
	{
		fill_chr(data, data->width, res, ' ');
		fill_chr(data, data->prec, res, '0');
	}
	if (data->i_param == 0)
	{
		if (data->prec == -1 && data->width != 0)
			fill_res(data, res, "\0");
		else if (data->prec == -1 && data->max_len == 1)
		{
			res[0] = '\0';
			data->max_len--;
		}
		else if (data->prec == 0)
			fill_res(data, res, "0");
	}
	else
		fill_res(data, res, p_abs);
	if (data->flag == '-')
		left_sort(res, data->max_len);
	return (res);
}

char	*s_exception(t_printf *data, char *res)
{
	if (data->flag == '0' && data->prec == 0)
		fill_chr(data, data->width, res, '0');
	else
		fill_chr(data, data->max_len, res, ' ');
	if (data->prec == -1 || data->prec > 0)
	{
		if (data->max_len != 0 && data->prec != -1)
			fill_s_res(data, res, data->str_param);
	}
	else
		fill_res(data, res, data->str_param);
	if (data->flag == '-')
		left_sort(res, data->max_len);
	return (res);
}

char	*ux_exception(t_printf *data, char *res, char *param)
{
	if (data->flag == '0' && data->prec == 0)
		fill_chr(data, data->width, res, '0');
	else
	{
		fill_chr(data, data->width, res, ' ');
		fill_chr(data, data->prec, res, '0');
	}
	if (data->prec == -1)
	{
		if (data->width > 0 && *param == '0')
		{
			fill_chr(data, data->width, res, ' ');
			return (res);
		}
		else if (data->width == 0 && *param == '0')
		{
			fill_chr(data, data->max_len, res, '\0');
			data->max_len--;
			return (res);
		}
	}
	fill_res(data, res, param);
	if (data->flag == '-')
		left_sort(res, data->max_len);
	return (res);
}

char	*p_exception(t_printf *data, char *res, char *param)
{
	if (data->flag == '0' && data->prec == 0)
		fill_chr(data, data->width, res, '0');
	else
		fill_chr(data, data->max_len, res, ' ');
	fill_res(data, res, param);
	if (data->flag == '-')
		left_sort(res, data->max_len);
	return (res);
}

char	*c_exception(t_printf *data, char *res, char *param)
{
	fill_chr(data, data->max_len, res, ' ');
	res[data->max_len - 1] = param[0];
	if (data->flag == '-')
		left_sort(res, data->max_len);
	return (res);
}
