/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uxX_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:43:22 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/22 22:31:55 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_uxX_maxlen(t_printf *data, int param_len)
{
	if (data->pres >= data->width)
		data->max_len = ((data->pres > param_len) ? data->pres : param_len);
	else
		data->max_len = ((data->width > param_len) ? data->width : param_len);
}

void	reverse_arr(char *arr)
{
	int i;
	int count;
	char temp;

	i = 0;
	count = ft_strlen(arr);

	while(i < count / 2)
	{
		temp = arr[i];
		arr[i] = arr[count - i - 1];
		arr[count - i - 1] = temp;
		i++;
	}
}
