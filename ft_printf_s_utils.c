/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 21:01:07 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/25 22:21:42 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_s_maxlen(t_printf *data, int param_len)
{
	if (data->prec == 0)
	{
		if (data->width >= param_len)
			data->max_len = data->width;
		else
			data->max_len = param_len;
	}
	else
	{
		if (param_len < data->width && param_len < data->prec)
			data->max_len = data->width;
		else if (data->width >= data->prec)
			data->max_len = data->width;
		else if (param_len < data->prec)
			data->max_len = param_len;
		else
			data->max_len = data->prec;
	}
}

void	fill_s_result(t_printf *data, char *res, char *param)
{
	int len;
	int max_len;

	max_len = data->max_len - 1;
	if ((int)ft_strlen(param) >= data->prec)
		len = data->prec - 1;
	else
		len = (int)ft_strlen(param) - 1;
	while (len != -1)
	{
		res[max_len] = param[len];
		max_len--;
		len--;
		if (len == -1)
			break ;
	}
}
