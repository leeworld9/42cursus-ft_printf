/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 20:48:24 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/25 22:27:08 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	show_result(t_printf *data)
{
	char	*result;
	int		len;

	if (data->width > 0)
		data->max_len = data->width;
	else
		data->max_len = 1;
	if ((result = (char *)malloc(sizeof(char) * (data->max_len + 1))) == NULL)
		return (0);
	result[data->max_len] = '\0';
	result[data->max_len - 1] = '%';
	len = data->max_len - 1;
	while (len > 0)
	{
		if (data->flag == '0')
			result[len - 1] = '0';
		else
			result[len - 1] = ' ';
		len--;
	}
	if (data->flag == '-')
		left_sort(result, data->max_len);
	ft_putstr_fd(result, 1);
	free(result);
	return (data->max_len);
}

int			ft_printf_percent(va_list ap, char *target, int i)
{
	t_printf	*data;
	int			len;

	len = 0;
	if ((data = (t_printf *)malloc(sizeof(t_printf))) == NULL)
		return (0);
	data->tag = ft_substr(target, 1, i);
	data->flag = '\0';
	data->width = 0;
	get_flag(data);
	get_width(ap, data);
	len += show_result(data);
	free(data->tag);
	free(data);
	return (len);
}
