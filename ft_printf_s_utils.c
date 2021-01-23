/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 21:01:07 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/23 13:52:01 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_s_maxlen(t_printf *data, int param_len)
{
	if (data->pres == 0)
	{
		if (data->width >= param_len)
			data->max_len = data->width;
		else
			data->max_len = param_len;
	}
	else
	{
		if (param_len < data->width && param_len < data->pres)
			data->max_len = data->width;
		else if (data->width >= data->pres)
			data->max_len = data->width;
		else if (param_len < data->pres)
			data->max_len = param_len;
		else
			data->max_len = data->pres;
	}
}

void	fill_s_result(t_printf *data, char *result, char *param)
{
	int len;
	int max_len;
	
	max_len = data->max_len - 1;
	if ((int)ft_strlen(param) >= data->pres)
		len = data->pres - 1;
	else
		len =(int)ft_strlen(param) - 1;
	while (len != -1)
	{
		result[max_len] = param[len];
		max_len--;
		len--;
		if (len == -1)
			break ;
	}
}
