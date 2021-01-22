/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 21:01:07 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/22 09:42:41 by dohelee          ###   ########.fr       */
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
		if (data->width >= data->pres)
			data->max_len = data->width;
		else
			data->max_len = data->pres;
	}
}
void	fill_s_result(t_printf *data, char *result, char *param)
{
	int len;
	int i;

	len = data->max_len - 1;
	while (len != -1)
	{
		result[len] = param[len];
		len--;
	}
	return ;
}