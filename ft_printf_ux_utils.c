/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ux_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 13:47:02 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/25 14:45:27 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_ux_maxlen(t_printf *data, int param_len)
{
	if (data->prec >= data->width)
		data->max_len = ((data->prec > param_len) ? data->prec : param_len);
	else
		data->max_len = ((data->width > param_len) ? data->width : param_len);
}

void	reverse_arr(char *arr)
{
	int		i;
	int		count;
	char	temp;

	i = 0;
	count = ft_strlen(arr);
	while (i < count / 2)
	{
		temp = arr[i];
		arr[i] = arr[count - i - 1];
		arr[count - i - 1] = temp;
		i++;
	}
}
