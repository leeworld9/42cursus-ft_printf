/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:09:05 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/23 15:27:20 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	show_result(t_printf *data)
{
	char	param[2];
	int		param_len;
	char	*result;

	param[0] = (char)data->param;
	param[1] = '\0';
	param_len = ft_strlen(param);
	get_c_maxlen(data, param_len);
	if ((result = (char *)malloc(sizeof(char) * (data->max_len + 1))) == NULL)
		return (0);
	result[data->max_len] = '\0';
	result = c_exception(data, result, param);
	ft_c_putstr_fd(data, result, 1);
	free(result);
	return (data->max_len);
}

int			ft_printf_c(va_list ap, char *target, int i)
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
	data->param = va_arg(ap, int);
	len += show_result(data);
	free(data->tag);
	free(data);
	return (len);
}
