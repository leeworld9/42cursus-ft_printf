/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_exception.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:50:29 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/22 09:39:54 by dohelee          ###   ########.fr       */
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
			// ft_putstr_fd(ft_itoa(data->max_len), 1);
			// ft_putstr_fd(", ", 1);
			// ft_putstr_fd(ft_itoa(data->pres), 1);
			fill_s_result(data, result, data->strparam);
		}
	}
	else
		fill_result(data, result, data->strparam);

	if (data->flag == '-')
		left_sort(result, data->max_len);
	return (result);
}
